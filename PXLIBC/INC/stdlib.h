#ifndef stlib_h
#define stlib_h
void srand(unsigned int seed);
int rand(void);
void* malloc(size_t size);
void free(void* ptr);
#endif