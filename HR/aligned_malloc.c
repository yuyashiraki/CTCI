#include <stdio.h>
#include <stdlib.h>

void *aligned_malloc(size_t bytes, size_t alignment)
{
    void *p1, *p2;
    p1 = (void*) malloc(alignment + bytes + sizeof(size_t));
    size_t addr = (size_t)p1 + alignment + sizeof(size_t);
    p2 = (void*)(addr - addr%alignment);
    *((size_t*)p2 - 1) = (size_t)p1;
    return p2;
}

void aligned_free(void *p)
{
    free((void*)(*((size_t*)p - 1)));
}

int main()
{
    int *p = aligned_malloc(sizeof(int), 16);
    printf("%p\n", (void*)p);
    aligned_free(p);
    return 0;
}
