# Malloc

## Introduction

This is **simple implementation** of malloc. This malloc is a way to get familiar with **memory allocation in C**.
If you are looking for a *more advanced* malloc implementation you can take a look at the [glibc implementation](https://github.com/lattera/glibc/blob/master/malloc/malloc.c).

## Summary

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

## Data-Structures overview
### Chunk
Each chunk has a **payload** *(where the user data is stored)* and **meta-data** about how big it is (via a size field in the chunk header). <br>
Chunks **payload address** is what is returned to the user.<br>
When a chunk is in use by the application, the only data that's "remembered" is the **size of the chunk**.<br>
You can use this size to find the next chunk in a **bin**.<br>

### Bin
Bins contains **multiples chunks**. <br>
They contain only a specific type of chunks, either only **SMALL** chunks or only **TINY** chunks.<br>
A bin can contain at least **100 chunks**.<br>
Each bins are the **same size** (e.g.: MAX_TINY_CHUNK_SIZE * 100 + headers).

### Zone
Zones contains **multipes bins**.<br>
Each zone is a **freelist** of all the bins in that specific zone.
In this implementation the zones are `[TINY, SMALL, LARGE]`, but you could have more zones.

### Global zone storage
This were all the zones are stored. This is a **global variable**. It can be access by **malloc and free**.

## Data-Structures details

## Functions Overview
### Malloc
Here is an **overview** of how this malloc implementation will work <br>

<details open><summary>1 - malloc</summary>
  <img src="https://raw.githubusercontent.com/gaeduron/Malloc/master/images/malloc_flowchart.png">
</details>

<details><summary>2 - find_space</summary>
  <img src="https://raw.githubusercontent.com/gaeduron/Malloc/master/images/malloc_find-space_flowchart.png">
</details>

<details><summary>3 - search_in_zone</summary>
  <img src="https://raw.githubusercontent.com/gaeduron/Malloc/master/images/malloc_search-in-zone_flowchart.png">
</details>

<details><summary>4 - create_bin</summary>
  <img src="https://raw.githubusercontent.com/gaeduron/Malloc/master/images/malloc_create-bin_flowchart.png">
</details>

### Free
### Realloc

## Documentation

**Glibc implementation of malloc()**
> [https://sourceware.org/glibc/wiki/MallocInternals](https://sourceware.org/glibc/wiki/MallocInternals)

**Really well documented implementation of malloc from glibc**
> [https://github.com/lattera/glibc/blob/master/malloc/malloc.c](https://github.com/lattera/glibc/blob/master/malloc/malloc.c)

**Good slides on mmap, sbrk, malloc** 
> [https://pubweb.eng.utah.edu/~cs4400/malloc.pdf](https://pubweb.eng.utah.edu/~cs4400/malloc.pdf)
