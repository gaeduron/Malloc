/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 13:00:13 by gduron            #+#    #+#             */
/*   Updated: 2019/05/05 18:31:24 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_malloc.h"

t_bin *g_zones[MAX_ZONE];

/*
** TODO: size might need to be a multiple of get page size
*/

int	free_bin(void *ptr, size_t size)
{
	t_bin	*bin;

	bin = (t_bin*)((size_t*)ptr - 3);
	remove_bin_from_zone(bin, LARGE);
	return (munmap((size_t*)ptr - 3, size) + 1);
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
		return (free_bin(ptr, chunk->size));
	return (1);
}
