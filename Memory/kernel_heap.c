typedef struct kblk 
{
    size_t size;           // payload size
    struct kblk* next;     // only valid when free
    int    free;
} kblk_t;

static kblk_t* g_free_list = NULL;
static uint8_t* g_heap_begin = NULL;
static uint8_t* g_heap_end = NULL;

// TODO: provide these
extern void* vm_map_new_heap_pages(size_t pages); // returns contiguous VA
extern void  vm_unmap_heap_pages(void* va, size_t pages);

static void kheap_add_region(void* va, size_t bytes) 
{
    kblk_t* b = (kblk_t*)va;
    b->size = bytes - sizeof(kblk_t);
    b->next = g_free_list;
    b->free = 1;
    g_free_list = b;
    if (!g_heap_begin || (uint8_t*)va < g_heap_begin) g_heap_begin = va;
    if ((uint8_t*)va + bytes > g_heap_end) g_heap_end = (uint8_t*)va + bytes;
}

void kheap_init(void* heap_base, size_t initial_size) 
{
    kheap_add_region(heap_base, initial_size);
}

static void kheap_grow(size_t min_bytes) 
{
    size_t pages = (min_bytes + PAGE_SIZE - 1) / PAGE_SIZE;
    if (pages < 16) pages = 16; // grow in chunks
    void* va = vm_map_new_heap_pages(pages);
    kheap_add_region(va, pages * PAGE_SIZE);
}

static void split_block(kblk_t* b, size_t need) 
{
    size_t remain = b->size - need;
    if (remain >= sizeof(kblk_t) + 16) {
        kblk_t* nb = (kblk_t*)((uint8_t*)b + sizeof(kblk_t) + need);
        nb->size = remain - sizeof(kblk_t);
        nb->free = 1;
        nb->next = b->next;
        b->size = need;
        b->next = nb;
    }
}

void* kmalloc(size_t n) 
{
    if (n == 0) n = 1;
    n = (n + 15) & ~15ULL; // 16-byte align payloads
    for (;;) 
    {
        kblk_t* prev = NULL;
        for (kblk_t* b = g_free_list; b; prev = b, b = b->next) 
        {
            if (b->free && b->size >= n) 
            {
                split_block(b, n);
                b->free = 0;
                // remove from free list
                if (prev) prev->next = b->next; else g_free_list = b->next;
                return (uint8_t*)b + sizeof(kblk_t);
            }
        }
        kheap_grow(n + sizeof(kblk_t));
    }
}

void kfree(void* p) 
{
    if (!p) return;
    kblk_t* b = (kblk_t*)((uint8_t*)p - sizeof(kblk_t));
    b->free = 1;
    // push-front
    b->next = g_free_list;
    g_free_list = b;

    // Optional: coalesce linearly adjacent blocks (single pass)
    for (kblk_t* cur = g_free_list; cur; cur = cur->next) 
    {
        uint8_t* cur_end = (uint8_t*)cur + sizeof(kblk_t) + cur->size;
        kblk_t* nxt = cur->next;
        if (nxt && nxt->free && (uint8_t*)nxt == cur_end) 
        {
            cur->size += sizeof(kblk_t) + nxt->size;
            cur->next = nxt->next;
        }
    }
}

void* kcalloc(size_t cnt, size_t sz)
{
    size_t n = cnt * sz;
    void* p = kmalloc(n);
    if (p) memset(p, 0, n);
    return p;
}

void* krealloc(void* p, size_t n) 
{
    if (!p) return kmalloc(n);

    if (n == 0) 
    { 
        kfree(p); return NULL; 
    }
    void* np = kmalloc(n);
    if (!np) return NULL;
    kblk_t* b = (kblk_t*)((uint8_t*)p - sizeof(kblk_t));
    size_t copy = b->size < n ? b->size : n;
    memcpy(np, p, copy);
    kfree(p);
    return np;
}
