/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:30:22 by gduron            #+#    #+#             */
/*   Updated: 2019/05/01 15:47:07 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_malloc.h"

void		*ft_mmap(size_t size)
{
	size_t n;
	size_t pagesize;

	pagesize = getpagesize();
	n = pagesize * ((size / pagesize) - (size % pagesize == 0) + 1);
	return (mmap(0, n, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0));
}

void	*set_bin_headers(void *memory, size_t size, t_bin *large_zone_head)
{
	t_bin new_bin;

	new_bin.last = 0;
	new_bin.next = large_zone_head;
	((t_bin*)memory)[0] = new_bin;
}
