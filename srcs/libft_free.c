/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 13:00:13 by gduron            #+#    #+#             */
/*   Updated: 2019/05/04 19:13:32 by gduron           ###   ########.fr       */
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
	t_bin	*prev_bin;
	t_bin	*next_bin;

	bin = (t_bin*)((size_t*)ptr - 3);
	prev_bin = bin->last;
	next_bin = bin->next;
	if (prev_bin != 0 && next_bin != 0)
	{
		prev_bin->next = next_bin;
		next_bin->last = prev_bin;
	}
	else if (prev_bin == 0)
	{
		g_zones[LARGE] = bin->next;
		if (bin->next)
			next_bin->last = 0;
	}
	else
		prev_bin->next = 0;
	return (munmap((size_t*)ptr - 3, size) + 1);
}

/*
** TODO: pointer being freed was not allocated error message
*/

int	ft_free(void *ptr)
{
	t_chunk	*chunk;
	t_chunk *next_chunk;

	if (ptr == 0)
		return (2);
	chunk = (t_chunk*)ptr - 1;
	next_chunk = (t_chunk*)((size_t*)ptr + chunk->size / 8 - 1);
	if ((next_chunk->size & 0b1) == 0)
		return (0);
	if (chunk->size > MAX_SMALL_CHUNK)
		return (free_bin(ptr, chunk->size));
	return (1);
}
