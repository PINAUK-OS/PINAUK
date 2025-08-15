#include "../PXLIBC/INC/stdlib.h"

char* strtok(char* str, char delim);
// ----------------------------
// VFS core
// ----------------------------
typedef enum {
    NODE_FILE,
    NODE_DIR,
    NODE_DEVICE
} node_type_t;

typedef struct vfs_node vfs_node_t;

typedef struct {
    int  (*open)(vfs_node_t *node);
    int  (*read)(vfs_node_t *node, void *buf, size_t size, size_t offset);
    int  (*write)(vfs_node_t *node, const void *buf, size_t size, size_t offset);
    void (*close)(vfs_node_t *node);
} vfs_ops_t;

struct vfs_node {
    char name[64];
    node_type_t type;

    vfs_node_t *parent;
    vfs_node_t *children;
    vfs_node_t *next_sibling;

    vfs_ops_t *ops;
    void *fs_data; // for device-specific data, inode, etc.
};

// Root FS node
vfs_node_t *vfs_root = NULL;

// ----------------------------
// Helper: create a new node
// ----------------------------
vfs_node_t* vfs_create_node(const char *name, node_type_t type, vfs_node_t *parent, vfs_ops_t *ops) {
    vfs_node_t *node = calloc(1, sizeof(vfs_node_t));
    strncpy(node->name, name, sizeof(node->name)-1);
    node->type = type;
    node->parent = parent;
    node->ops = ops;

    // Link into parent's child list
    if (parent) {
        node->next_sibling = parent->children;
        parent->children = node;
    }
    return node;
}

// ----------------------------
// Lookup by absolute path
// ----------------------------
vfs_node_t* vfs_lookup(const char *path) {
    if (!path || path[0] != '/') return NULL;

    char tmp[256];
    strncpy(tmp, path, sizeof(tmp)-1);
    tmp[sizeof(tmp)-1] = 0;

    vfs_node_t *node = vfs_root;
    char *tok = strtok(tmp, "/");
    while (tok && node) {
        vfs_node_t *child = node->children;
        node = NULL;
        while (child) {
            if (strcmp(child->name, tok) == 0) {
                node = child;
                break;
            }
            child = child->next_sibling;
        }
        tok = strtok(NULL, "/");
    }
    return node;
}
