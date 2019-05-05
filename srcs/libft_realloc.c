/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_realloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 10:51:25 by gduron            #+#    #+#             */
/*   Updated: 2019/05/05 11:20:10 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_malloc.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;
	size_t	current_size;

	current_size = chunk_remove_flags(mem_to_chunk_ptr(ptr)->size);
	if (current_size > size)
		new_ptr = ft_memcpy(malloc(size), ptr, size);
	else
		new_ptr = ft_memcpy(malloc(size), ptr, current_size);
	free(ptr);
	return (new_ptr);
}
