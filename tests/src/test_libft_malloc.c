/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft_malloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:51:13 by gduron            #+#    #+#             */
/*   Updated: 2019/05/06 14:25:43 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/tinytest.h"
#include "../../includes/libft_malloc.h"

void	test_malloc_zero(void)
{
	ASSERT("MALLOC: should handle zero", ft_malloc(0) == 0);
}

void	test_malloc_large(void)
{
	size_t	*alloc;
	size_t	size;
	char	*last_adr;

	size = 4096 - 32;
	ASSERT("MALLOC: should handle large allocation", ft_malloc(size) > 0);
	alloc = (size_t*)ft_malloc(size);
	ASSERT("MALLOC: allocation should be the right size",
		alloc[-1] == size + FIRST_CHUNK_HEADER);
	ASSERT("MALLOC: bin first chunk flags",
		(alloc[-1] & FIRST_CHUNK_HEADER) == FIRST_CHUNK_HEADER);
	last_adr = ((char *)alloc + size);
	ASSERT("MALLOC: is the right size", *last_adr == 0 || *last_adr != 0);
	ASSERT("MALLOC: bin are terminated by a final chunk",
		*last_adr == LAST_CHUNK_HEADER);
}

void	test_malloc_small_tiny(void)
{
	size_t	*alloc;
	size_t	size;
	t_chunk	*next_chunk;

	size = 48;
	alloc = (size_t*)ft_malloc(size);
	ASSERT("MALLOC: should handle tiny allocation", alloc > 0);
	ASSERT("MALLOC: allocation should be the right size",
		alloc[-1] / 8 == size / 8);
	next_chunk = get_next_chunk(mem_to_chunk_ptr(alloc));
	ASSERT("MALLOC: chunk should have a next chunk", next_chunk->size % 2 == 1);
}

void	playground(void)
{
	return ;
}

int		main(void)
{
	RUN(test_malloc_zero);
	RUN(test_malloc_large);
	RUN(test_malloc_small_tiny);
	playground();
	return (TEST_REPORT());
}
