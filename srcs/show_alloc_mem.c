/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 14:34:22 by gduron            #+#    #+#             */
/*   Updated: 2019/05/04 16:18:05 by gduron           ###   ########.fr       */
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
	ft_printf("\n%p - %p : %zu bytes\n",
		chunk_start, chunk_end, ((chunk->size >> 3) << 3), *chunk_end);
	return ;
}

// void	show_zone(t_bin *head_bin)
// {
// 	return ;
// }

void	show_alloc_mem(void)
{
	int i;

	i = 0;
	while (i < MAX_ZONE)
	{
		//show_zone(g_zones[i]);
		ft_printf("\nShowing zone: %d", i);
		i++;
	}
	ft_printf("\n");
	return ;
}
