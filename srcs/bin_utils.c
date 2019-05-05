/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 20:55:15 by gduron            #+#    #+#             */
/*   Updated: 2019/05/05 14:43:48 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_malloc.h"

t_chunk	*bin_get_first_chunk(t_bin *bin)
{
	return ((t_chunk*)((size_t*)bin + 1));
}

t_bin	*remove_bin_from_zone(t_bin *bin, int zone)
{
	t_bin	*prev_bin;
	t_bin	*next_bin;

	prev_bin = bin->last;
	next_bin = bin->next;
	if (prev_bin != 0 && next_bin != 0)
	{
		prev_bin->next = next_bin;
		next_bin->last = prev_bin;
	}
	else if (prev_bin == 0)
	{
		g_zones[zone] = bin->next;
		if (bin->next)
			next_bin->last = 0;
	}
	else
		prev_bin->next = 0;
	return (bin);
}

t_bin	*add_bin_to_zone(t_bin *bin, int zone)
{
	t_bin	*head_bin;

	bin->last = 0;
	bin->next = g_zones[zone];
	head_bin = g_zones[zone];
	if (head_bin)
		head_bin->last = bin;
	g_zones[zone] = bin;
	return (bin);
}
