/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 14:34:22 by gduron            #+#    #+#             */
/*   Updated: 2019/05/04 15:03:21 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_malloc.h"

t_bin *g_zones[MAX_ZONE];

// void	show_chunks(t_bin *head_bin)
// {
// 	return ;
// }

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
		i++;
	}
	return ;
}
