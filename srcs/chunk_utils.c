/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 20:17:24 by gduron            #+#    #+#             */
/*   Updated: 2019/05/04 20:38:49 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_malloc.h"

size_t	chunk_remove_flags(size_t size)
{
	return ((size >> 3) << 3);
}

t_chunk	*next_chunk(t_chunk *chunk)
{
	return ((t_chunk*)((size_t*)chunk + chunk->size / 8 + 1));
}

size_t	*chunk_to_mem_ptr(t_chunk *chunk)
{
	return ((size_t*)(chunk + 1));
}
