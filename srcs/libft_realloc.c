/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_realloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 10:51:25 by gduron            #+#    #+#             */
/*   Updated: 2019/05/05 12:50:40 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_malloc.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;
	size_t	current_size;

	current_size = chunk_remove_flags(mem_to_chunk_ptr(ptr)->size);
	if (current_size >= size)
		return (ptr);
	if (current_size > MAX_SMALL_CHUNK)
	{
		if ((current_size + 32 - 8) / 4096 == (size + 32) / 4096)
			return (ptr);
	}
	new_ptr = ft_memcpy(ft_malloc(size), ptr, current_size);
	ft_free(ptr);
	return (new_ptr);
}
