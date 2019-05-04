/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 14:34:22 by gduron            #+#    #+#             */
/*   Updated: 2019/05/04 20:23:36 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_malloc.h"

t_bin *g_zones[MAX_ZONE];

/*
** It would be nice to refacto usual operation such as:
** `chunk to next chunk` OR `remove flags from size`
*/

void	show_chunk(t_chunk *chunk)
{
	size_t	*chunk_start;
	size_t	*chunk_end;

	chunk_start = (size_t*)(chunk + 1);
	chunk_end = chunk_start + chunk->size / 8 - 1;
	ft_printf("%p - %p : %zu bytes\n",
		chunk_start, chunk_end, chunk_remove_flags(chunk->size), *chunk_end);
	return ;
}

void	go_through_zone(t_bin *head_bin)
{
	t_bin	*bin;
	t_chunk	*chunk;

	bin = head_bin;
	while (bin != 0)
	{
		chunk = (t_chunk*)((size_t*)bin + 1);
		while ((chunk->size & LAST_CHUNK_FLAG) == 0)
		{
			show_chunk(chunk);
			chunk = (t_chunk*)((size_t*)chunk + chunk->size / 8 + 1);
		}
		bin = bin->next;
	}
	return ;
}

void	show_alloc_mem(void)
{
	int		i;
	char	*zones[MAX_ZONE];

	zones[0] = "TINY";
	zones[1] = "SMALL";
	zones[2] = "LARGE";
	i = 0;
	while (i < MAX_ZONE)
	{
		ft_printf("%s : %p\n", zones[i], g_zones[i]);
		if (g_zones[i] != 0)
			go_through_zone(g_zones[i]);
		i++;
	}
	ft_printf("\n");
	return ;
}
