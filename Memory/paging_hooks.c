// Map 'pages' physical pages from PMM and return a contiguous VA for the heap.
void* vm_map_new_heap_pages(size_t pages) 
{
    void* pa = pmm_alloc_pages(pages);
    if (!pa) return NULL;
    // TODO: uint64_t base_va = /* pick next free heap VA range */;
    for (size_t i = 0; i < pages; ++i) 
    {
        uint64_t this_pa = (uint64_t)(uintptr_t)pa + i * PAGE_SIZE;
        // TODO: uint64_t this_va = base_va + i * PAGE_SIZE;
        // map with RW, NX, global
        // TODO: map_page(this_va, this_pa, flags);
    }
    // flush TLB for range if needed
    // TODO: return (void*)(uintptr_t)base_va;
}

// For completeness—rarely used for kernel heap shrink in early kernels.
void vm_unmap_heap_pages(void* va, size_t pages) 
{
    for (size_t i = 0; i < pages; ++i) 
    {
        uint64_t pa = walk_page_tables_and_unmap((uint64_t)va + i * PAGE_SIZE);
        pmm_free_page((void*)pa);
    }
}
