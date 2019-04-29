# Malloc

## Introduction

**⚠️THIS REPO IS A WORK IN PROGRESS AT THIS POINT**

This is **simple implementation** of malloc. This malloc is a way to get familiar with **memory allocation in C**.
If you are looking for a *more advanced* malloc implementation you can take a look at the [glibc implementation](https://github.com/lattera/glibc/blob/master/malloc/malloc.c).

## Summary

1. [Guideline](#guideline)
2. [Data-Structures overview](#data-structures-overview)
3. [Data-Structures details](#data-structures-details)
    1. [Chunk](#chunk-1)
    2. [Bin](#bin-1)
    3. [Zone](#zone-1)
    4. [Global zone storage](#global-zone-storage-1)
4. [Functions Overview](#functions-overview)
    1. [Malloc](#malloc-1)
    2. [Free](#free)
    3. [Realloc](#realloc)
5. [Documentation](#documentation)

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
### Chunk


Chunks are **8 bytes aligned**
The **minimum size** of a chunk is `2*sizeof(void*)`. Usually `sizeof(void*)` is `sizeof(size_t)`.
You can find the size of your *size_t* with this command:

```sh
echo | gcc -E -xc -include 'stddef.h' - | grep size_t
```

A chunk in use:
```
- schema -
|---|---|---|---|---|---|---|---|
|   size_of_the_chunk       |  P|    P = Previous chunk is in use
|---|---|---|---|---|---|---|---|
|            payload            |
|                               |
|                               |
|                               |
|---|---|---|---|---|---|---|---|
	
- example -
|---|---|---|---|---|---|---|---|
|x00  00  00  00  00  00  20| 01|    Size = 32 bytes, P = true 
|---|---|---|---|---|---|---|---|
|            payload            |    Payload = User data
|                               |
|                               |
|                               |
|---|---|---|---|---|---|---|---|
```

In a **free chunk** we also have at the end the size of the chunk. That way we can *navigate back* in our bin.
We will use this way of navigation during the **memory defragmentation** process.
Where we want to combine free chunk with adjacent free chunks to **"coalesce"** them into larger chunks.

A free chunk:
```
- schema -
|---|---|---|---|---|---|---|---|
|   size_of_the_chunk       |  P|
|---|---|---|---|---|---|---|---|
|            payload            |
|                               |
|                               |
|---|---|---|---|---|---|---|---|
|       size_of_the_chunk       |
|---|---|---|---|---|---|---|---|

- example -
|---|---|---|---|---|---|---|---|
|x00  00  00  00  00  00  20| 01|    Size = 32 bytes, P = true 
|---|---|---|---|---|---|---|---|
|            payload            |    Payload = User data
|                               |
|                               |
|---|---|---|---|---|---|---|---|
|x00  00  00  00  00  00  20| 00|
|---|---|---|---|---|---|---|---|
```
Now let's see an exemple with 3 adjacent chunks

```
|---|---|---|---|---|---|---|---|
|x00  00  00  00  00  00  20| 01|    | Chunk 1
|---|---|---|---|---|---|---|---|    | Size = 32 bytes, previous chunk is used
|            payload            |    | Is now free
|                               |    |
|                               |    |
|---|---|---|---|---|---|---|---|
|x00  00  00  00  00  00  20| 01|
|---|---|---|---|---|---|---|---|
|x00  00  00  00  00  00  18| 00|    | Chunk 2 
|---|---|---|---|---|---|---|---|    | Size = 24 bytes, previous chunk is free
|            payload            |    | Is now in use
|                               |    |
|                               |    |
|---|---|---|---|---|---|---|---|
|x00  00  00  00  00  00  08| 03|    | Chunk 3
|---|---|---|---|---|---|---|---|    | Size = 24 bytes, previous chunk is used
|            payload            |    | Is the last chunk of the bin
|---|---|---|---|---|---|---|---|
```

In the last chunk we have **P = 3**, this mean that it's the **last chunk** of the bin.
Because our chunk are aligned on 8 bytes, we can use the three *least significant* bits of our size to set some **flags**.

```
Chunk 1 header in binary
                                                                    | LP
|--------|--------|--------|--------|--------|--------|--------|--------|
|00000000|00000000|00000000|00000000|00000000|00000000|00100000|00000001|
|--------|--------|--------|--------|--------|--------|--------|--------|

Chunk 3 header in binary
                                                                    | LP			
|--------|--------|--------|--------|--------|--------|--------|--------|
|00000000|00000000|00000000|00000000|00000000|00000000|00001000|00000011|
|--------|--------|--------|--------|--------|--------|--------|--------|
```

So the L flag  mean that this is the last chunk in a bin.


### Bin

### Zone

### Global zone storage


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
