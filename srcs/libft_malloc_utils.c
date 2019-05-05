/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_malloc_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 13:51:29 by gduron            #+#    #+#             */
/*   Updated: 2019/05/05 14:33:44 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_malloc.h"

t_bin *g_zones[MAX_ZONE];

void	*set_chunk_header(t_chunk *chunk)
{
	return (chunk);
}

void	*search_in_zone(size_t size, int zone)
{
	zone = 0;
	size = 0;
	return (0);
}

int		create_bin(int zone)
{
	t_bin	*bin;
	int		bin_size[2];

	bin_size[0] = MAX_TINY_CHUNK * 100;
	bin_size[1] = MAX_SMALL_CHUNK * 100;
	bin = ft_malloc(bin_size[zone]);
	remove_bin_from_zone(bin, LARGE);
	add_bin_to_zone(bin, zone);
	return (0);
}
