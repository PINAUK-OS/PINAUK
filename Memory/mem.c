// Memory allocator
#include "mem_init_stuff.c"
//#include "../PXLIBC/INC/stdbool.h"
#include <stdbool.h>

typedef struct {
	uint32_t Type;		// EFI_MEMORY_TYPE
	uint32_t Pad;
	uint64_t PhysicalStart;	// Starting physical address of the memory region
	uint64_t VirtualStart;	// Starting virtual address of the memory region
	uint64_t NumberOfPages;	// Number of pages in the memory region
	uint64_t Attribute;	// Attributes of the memory region
} efi_mmap_desc_t;

typedef struct {
	uint64_t mmap;
	uint64_t mmap_size;	// bytes
	uint64_t desc_size;
	uint32_t desc_ver;
	uint64_t kernel_start_pa, kernel_end_pa;
	uint64_t fb_pa, fb_size;	// framebuffer physical address and size
} boot_info_t;


#define PAGE_SIZE 4096ULL

typedef struct {
	uint64_t* map;
	uint64_t bits;
} pmm_bitmap_t;

static pmm_bitmap_t g_pmm;
static uint64_t g_total_pages = 0;
static uint64_t g_free_pages = 0;

static inline void bset(uint64_t i) { g_pmm.map[i / 64] |= (1ULL << (i % 64)); }
static inline void bclr(uint64_t i) { g_pmm.map[i / 64] &= ~(1ULL << (i % 64)); }
static inline bool bget(uint64_t i) { return (g_pmm.map[i / 64] >> (i % 64)) & 1ULL; }

static inline uint64_t align_up(uint64_t v, uint64_t a) { return (v + a - 1) & ~(a - 1); }

/*enum {
    EfiReservedMemoryType = 0,
    EfiLoaderCode = 1,
    EfiLoaderData = 2,
    EfiBootServicesCode = 3,
    EfiBootServicesData = 4,
    EfiRuntimeServicesCode = 5,
    EfiRuntimeServicesData = 6,
    EfiConventionalMemory = 7,
    EfiUnusableMemory = 8,
    EfiACPIReclaimMemory = 9,
    EfiACPIMemoryNVS = 10,
    EfiMemoryMappedIO = 11,
    EfiMemoryMappedIOPortSpace = 12,
    EfiPalCode = 13,
    // ... (others exist)
};*/

typedef struct {
    boot_info_t bi;
    // fill this before calling pmm_init
} pmm_init_args_t;

// TODO: provide these from your paging layer.
extern void* va_map_temp_pages(uint64_t pa, size_t pages); // scratch mapping for bitmap if needed

static void mark_range(uint64_t pa, uint64_t size, bool used) {
    uint64_t first = pa / PAGE_SIZE;
    uint64_t last = (pa + size + PAGE_SIZE - 1) / PAGE_SIZE; // exclusive
    if (last > g_pmm.bits) last = g_pmm.bits;
    for (uint64_t i = first; i < last; ++i) {
        bool was = bget(i);
        if (used) { if (!was) { bset(i); if (g_free_pages) g_free_pages--; } }
        else { if (was) { bclr(i); g_free_pages++; } }
    }
}

// Choose a place for the bitmap: grab from the largest Conventional range.
static uint64_t choose_bitmap_pa_and_size(const efi_mmap_desc_t* d, size_t cnt,
    size_t bytes_need, uint64_t* out_pages)
{
    uint64_t best_len = 0, best_pa = 0;
    for (size_t i = 0; i < cnt; ++i) {
        if (d[i].Type != EfiConventionalMemory) continue;
        uint64_t pa = d[i].PhysicalStart;
        uint64_t len = d[i].NumberOfPages * PAGE_SIZE;
        if (len > best_len) { best_len = len; best_pa = pa; }
    }
    uint64_t pages = align_up(bytes_need, PAGE_SIZE) / PAGE_SIZE;
    if (best_len < pages * PAGE_SIZE) return 0;
    *out_pages = pages;
    return best_pa;
}

void pmm_init(const pmm_init_args_t* args)
{
    const uint8_t* mmap_bytes = (const uint8_t*)(uintptr_t)args->bi.mmap;
    size_t descs = args->bi.mmap_size / args->bi.desc_size;


    uint64_t max_end = 0;
    for (size_t i = 0; i < descs; ++i) {
        const efi_mmap_desc_t* d = (const efi_mmap_desc_t*)(mmap_bytes + i * args->bi.desc_size);
        uint64_t end = d->PhysicalStart + d->NumberOfPages * PAGE_SIZE;
        if (end > max_end) max_end = end;
        g_total_pages += d->NumberOfPages;
    }
    g_pmm.bits = max_end / PAGE_SIZE;

    size_t bitmap_bytes = align_up(g_pmm.bits, 8) / 8; // bits => bytes
    uint64_t bitmap_pages = 0;
    uint64_t bitmap_pa = choose_bitmap_pa_and_size(
        (const efi_mmap_desc_t*)mmap_bytes, descs, bitmap_bytes, &bitmap_pages);

    void* bitmap_va = va_map_temp_pages(bitmap_pa, bitmap_pages);
    g_pmm.map = (uint64_t*)bitmap_va;
    memset(g_pmm.map, 0xFF, bitmap_pages * PAGE_SIZE); // mark all used initially
    g_free_pages = 0;

    for (size_t i = 0; i < descs; ++i) {
        const efi_mmap_desc_t* d = (const efi_mmap_desc_t*)(mmap_bytes + i * args->bi.desc_size);
        if (d->Type == EfiConventionalMemory) {
            mark_range(d->PhysicalStart, d->NumberOfPages * PAGE_SIZE, false);
        }
    }

    mark_range(bitmap_pa, bitmap_pages * PAGE_SIZE, true);
    if (args->bi.kernel_start_pa && args->bi.kernel_end_pa)
        mark_range(args->bi.kernel_start_pa,
            args->bi.kernel_end_pa - args->bi.kernel_start_pa, true);
    if (args->bi.fb_pa && args->bi.fb_size)
        mark_range(args->bi.fb_pa, args->bi.fb_size, true);
    // Reserve first 1 MiB if you like:
    mark_range(0, 0x100000, true);

    // Also reserve the memory map buffer itself:
    mark_range(args->bi.mmap, args->bi.mmap_size, true);
}

void* pmm_alloc_page(void)
{
    for (uint64_t i = 0; i < g_pmm.bits; ++i) {
        if (!bget(i)) {
            bset(i);
            if (g_free_pages) g_free_pages--;
            return (void*)(uintptr_t)(i * PAGE_SIZE);
        }
    }
    return NULL;
}

void  pmm_free_page(void* pa)
{
    uint64_t i = (uint64_t)(uintptr_t)pa / PAGE_SIZE;
    if (i < g_pmm.bits && bget(i)) {
        bclr(i);
        g_free_pages++;
    }
}

void* pmm_alloc_pages(size_t n)
{
    if (n == 0) return NULL;
    size_t run = 0; uint64_t start = 0;
    for (uint64_t i = 0; i < g_pmm.bits; ++i) {
        if (!bget(i)) {
            if (run == 0) start = i;
            if (++run == n) {
                for (uint64_t j = start; j < start + n; ++j) bset(j);
                if (g_free_pages >= n) g_free_pages -= n;
                return (void*)(uintptr_t)(start * PAGE_SIZE);
            }
        }
        else {
            run = 0;
        }
    }
    return NULL;
}

void pmm_free_pages(void* pa, size_t n)
{
    uint64_t start = (uint64_t)(uintptr_t)pa / PAGE_SIZE;
    for (uint64_t j = start; j < start + n && j < g_pmm.bits; ++j) {
        if (bget(j)) { bclr(j); g_free_pages++; }
    }
}

size_t pmm_total(void) { return (size_t)g_pmm.bits * PAGE_SIZE; }
size_t pmm_free(void) { return (size_t)g_free_pages * PAGE_SIZE; }



// I'm tired of pretending I write this all myself without using ChatGPT
static uint8_t* g_early_base = NULL;
static uint8_t* g_early_ptr = NULL;
static uint8_t* g_early_end = NULL;

void early_heap_init(void* base, size_t size) {
    g_early_base = g_early_ptr = (uint8_t*)base;
    g_early_end = g_early_base + size;
}

void* early_alloc(size_t n, size_t align) {
    uintptr_t p = (uintptr_t)g_early_ptr;
    uintptr_t a = (p + (align - 1)) & ~(align - 1);
    if (a + n > (uintptr_t)g_early_end) return NULL;
    g_early_ptr = (uint8_t*)(a + n);
    return (void*)a;
}
