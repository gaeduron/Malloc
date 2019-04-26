#include "libft_malloc.h"

void *malloc(size_t len)
{
	return mmap(0, len, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
}
