/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_malloc_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 13:51:29 by gduron            #+#    #+#             */
/*   Updated: 2019/05/15 18:45:10 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_malloc.h"

t_bin *g_zones[MAX_ZONE];

void	*set_chunk_header(t_chunk *chunk, size_t size, int zone)
{
	int		min_chunk[2];
	size_t	first_size;
	t_chunk *next_chunk;

	min_chunk[0] = 8 + 8;
	min_chunk[1] = MAX_TINY_CHUNK + 8 + 8;
	if (chunk->size >= size + min_chunk[zone])
	{
		first_size = chunk->size;
		chunk->size = first_size - size - 8;
		next_chunk = get_next_chunk(chunk);
		next_chunk->size = size;
		next_chunk->prev_size = chunk->size;
		chunk = next_chunk;
		next_chunk = get_next_chunk(chunk);
		next_chunk->size |= PREVIOUS_CHUNK_USED_FLAG;
	}
	else
	{
		next_chunk = get_next_chunk(chunk);
		next_chunk->size |= PREVIOUS_CHUNK_USED_FLAG;
	}
	return ((size_t*)chunk + 2);
}

void	*search_in_zone(size_t size, int zone)
{
	t_bin	*bin;
	t_chunk	*chunk;

	bin = g_zones[zone];
	while (bin != 0)
	{
		chunk = bin_get_first_chunk(bin);
		while ((chunk->size & LAST_CHUNK_FLAG) == 0)
		{
			if (chunk->size >= size && get_next_chunk(chunk)->size % 2 == 0)
				return (set_chunk_header(chunk, size, zone));
			chunk = get_next_chunk(chunk);
		}
		bin = bin->next;
	}
	return (0);
}

int		create_bin(int zone)
{
	t_bin	*bin;
	int		bin_size[2];
	t_chunk	*last_chunk;

	bin_size[0] = (MAX_TINY_CHUNK + 8) * 100;
	bin_size[1] = (MAX_SMALL_CHUNK + 8) * 100;
	bin = (t_bin*)((size_t*)ft_malloc(bin_size[zone]) - 3);
	remove_bin_from_zone(bin, LARGE);
	add_bin_to_zone(bin, zone);
	last_chunk = get_next_chunk(bin_get_first_chunk(bin));
	last_chunk->size = LAST_CHUNK_FLAG;
	return (0);
}
