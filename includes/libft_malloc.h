#ifndef MALLOC_H
# define MALLOC_H

# include <sys/mman.h>
# include <unistd.h>

void	*malloc(size_t size);
void    *ft_mmap(size_t size);
#endif
