/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 13:00:13 by gduron            #+#    #+#             */
/*   Updated: 2019/05/03 13:36:42 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_malloc.h"

int		free_bin(void *ptr)
{
	
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
		return (free_bin(ptr));
	return (1);
}

