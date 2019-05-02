/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:30:22 by gduron            #+#    #+#             */
/*   Updated: 2019/05/02 16:11:21 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_malloc.h"

void	*ft_mmap(size_t size)
{
	size_t	n;
	size_t	pagesize;

	pagesize = getpagesize();
	n = pagesize * ((size / pagesize) - (size % pagesize == 0) + 1);
	return (mmap(0, n, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0));
}

void	*set_bin_headers(void *memory, size_t size)
{
	t_bin new_bin;

	new_bin.last = 0;
	new_bin.next = g_zones[LARGE];
	((t_bin*)memory)[0] = new_bin;
	g_zones[LARGE] = &new_bin;
	((size_t*)memory)[2] = size;
	return (memory);
}

void	*find_space(size_t size, int zone)
{
	if (zone == LARGE)
		return (set_bin_headers(ft_mmap(size), size));
	return (0);
}

t_bin *g_zones[MAX_ZONE];

void	*ft_malloc(size_t size)
{
	int zone;

	if (size == 0)
		return (0);
	zone = (size > MAX_TINY_CHUNK) + (size > MAX_SMALL_CHUNK);
	return (find_space(size, zone));
}
