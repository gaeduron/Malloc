/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:30:22 by gduron            #+#    #+#             */
/*   Updated: 2019/05/05 13:49:20 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_malloc.h"

t_bin *g_zones[MAX_ZONE];

void	*ft_mmap(size_t size)
{
	size_t	n;
	size_t	pagesize;
	void	*memory;

	pagesize = getpagesize();
	size += BIN_HEADERS_SIZE;
	n = pagesize * ((size / pagesize) - (size % pagesize == 0) + 1);
	memory = mmap(0, n, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	return ((size_t*)memory);
}

void	*set_bin_headers(size_t *memory, size_t size)
{
	t_bin	new_bin;
	t_bin	*head_bin;
	t_chunk	*first_chunk;
	t_chunk	*last_chunk;

	new_bin.last = 0;
	new_bin.next = g_zones[LARGE];
	((t_bin*)memory)[0] = new_bin;
	head_bin = g_zones[LARGE];
	if (head_bin)
		head_bin->last = (t_bin*)memory;
	g_zones[LARGE] = (t_bin*)memory;
	head_bin = (t_bin*)memory;
	first_chunk = bin_get_first_chunk(head_bin);
	first_chunk->size = chunk_remove_flags(size) + 0b101;
	last_chunk = get_next_chunk(first_chunk);
	last_chunk->size = LAST_CHUNK_HEADER;
	return (chunk_to_mem_ptr(first_chunk));
}

void	*find_space(size_t size, int zone)
{
	void	*alloc;

	if (zone == LARGE)
		return (set_bin_headers(ft_mmap(size), size));
	alloc = search_in_zone(size, zone);
	if (alloc)
		return (alloc);
	create_bin(zone);
	return (find_space(size, zone));
}

void	*ft_malloc(size_t size)
{
	int zone;

	if (size == 0)
		return (0);
	zone = (size > MAX_TINY_CHUNK) + (size > MAX_SMALL_CHUNK);
	size = size + (size % 8 != 0 ? 8 - size % 8 : 0);
	return (find_space(size, zone));
}
