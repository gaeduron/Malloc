# Malloc

## Documentation

**Glibc implementation of malloc()**
> [https://sourceware.org/glibc/wiki/MallocInternals](https://sourceware.org/glibc/wiki/MallocInternals)

**Really well documented implementation of malloc from glibc**
> [https://github.com/lattera/glibc/blob/master/malloc/malloc.c](https://github.com/lattera/glibc/blob/master/malloc/malloc.c)

**Good slides on mmap, sbrk, malloc** 
> [https://pubweb.eng.utah.edu/~cs4400/malloc.pdf](https://pubweb.eng.utah.edu/~cs4400/malloc.pdf)

## Guideline

This malloc implementation is **different** from the glibc. The constrain for this project are:

-  You can only use some **allowed functions**:
  ```C
  mmap(2)
  munmap(2)
  getpagesize(3)
  getrlimit(2)
  The authorized functions within your libft (write(2) par exemple ;-) )
  The functions from libpthread
  ```
  
- The project must be written in accordance with the **42 Norm**
- You have to “pre-allocate” some memory zones to store your “small”
and “medium” malloc.
-  Each zone must contain at least 100 allocations.
  ```
  “TINY” mallocs, from 1 to n bytes, will be stored in N bytes big zones.<br>
  “SMALL” mallocs, from (n+1) to m bytes, will be stored in M bytes big zones.<br>
  “LARGE” mallocs, fron (m+1) bytes and more, will be stored out of zone,<br>
  which simply means with mmap(), they will be in a zone on their own.<br>
  ```

## Structures
### Global zone storage
### Zone
### Bin
### Chunk

## Functions Overview
### Malloc
Here is an **overview** of how this malloc implementation will work <br>
**1 - malloc**

![malloc_flowchart](https://raw.githubusercontent.com/gaeduron/Malloc/master/images/malloc_flowchart.png)

### Free
### Realloc
