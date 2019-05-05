/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 13:00:13 by gduron            #+#    #+#             */
/*   Updated: 2019/05/05 19:22:56 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_malloc.h"

t_bin *g_zones[MAX_ZONE];

/*
** TODO: size might need to be a multiple of get page size
*/

int	free_bin(void *ptr, size_t size, int zone)
{
	t_bin	*bin;

	bin = (t_bin*)((size_t*)ptr - 3);
	remove_bin_from_zone(bin, zone);
	return (munmap((size_t*)ptr - 3, size) + 1);
}

int	bin_is_empty(t_chunk *chunk, t_chunk *next_chunk)
{
	if (chunk->size & FIRST_CHUNK_FLAG)
	{
		if (next_chunk->size & LAST_CHUNK_FLAG)
			return (1);
	}
	return (0);
}

int	free_chunk(t_chunk *chunk)
{
	t_chunk	*next_chunk;
	t_chunk	*prev_chunk;

	next_chunk = get_next_chunk(chunk);
	prev_chunk = get_prev_chunk(chunk);
	next_chunk->size &= ~(1UL);
	next_chunk->prev_size = chunk_remove_flags(chunk->size);
	if (!(next_chunk->size & LAST_CHUNK_FLAG) && \
		get_next_chunk(next_chunk)->size % 2)
		chunk->size += chunk_remove_flags(next_chunk->size) + 8;
	if (chunk->size % 2 && !(chunk->size & FIRST_CHUNK_FLAG))
		prev_chunk->size += chunk_remove_flags(chunk->size) + 8;
	if (bin_is_empty(chunk, next_chunk))
	{
		return (free_bin(chunk_to_mem_ptr(chunk), chunk->size,
			find_zone(first_chunk_get_bin(chunk))));
	}
	return (1);
}

int	ft_free(void *ptr)
{
	t_chunk	*chunk;
	t_chunk *next_chunk;

	if (ptr == 0)
		return (2);
	chunk = mem_to_chunk_ptr(ptr);
	next_chunk = get_next_chunk(chunk);
	if ((next_chunk->size & 0b1) == 0)
	{
		ft_printf("malloc: *** error for object %p: \
		pointer being freed was not allocated", ptr);
		return (0);
	}
	if (chunk->size > MAX_SMALL_CHUNK)
		return (free_bin(ptr, chunk->size, LARGE));
	return (free_chunk(chunk));
}
