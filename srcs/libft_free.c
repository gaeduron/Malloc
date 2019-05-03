/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 13:00:13 by gduron            #+#    #+#             */
/*   Updated: 2019/05/03 14:17:50 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_malloc.h"

/* TODO: size might need to be a multiple of get page size */
int		free_bin(void *ptr, size_t size)
{
	t_bin	*bin;
	t_bin	*prev_bin;
	t_bin	*next_bin;

	bin = (size_t*)ptr - 3;
	prev_bin = bin->last;
	next_bin = bin->next;
	if (prev_bin != 0 && next_bin != 0)
	{
		prev_bin->next = next_bin;
		next_bin->last = prev_bin;
	}
	else if (prev_bin == 0)
		g_zones[LARGE] = bin->next;
	else
		prev_bin->next = 0;
	return (munmap((size_t*)ptr - 3, size) + 1);
}

/* TODO: pointer being freed was not allocated error message*/
int		free(void *ptr)
{
	t_chunk	*chunk;

	if (ptr == 0)
		return (2);
	chunk = (*t_chunk)ptr - 1;
	if (!(chunk[(chunk->size / 16)].size & 0b1))
		return (0);
	if (chunk->size > MAX_SMALL_CHUNK)
		return (free_bin(ptr, chunk->size));
	return (1);
}