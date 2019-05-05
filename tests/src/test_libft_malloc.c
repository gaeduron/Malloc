/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft_malloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:51:13 by gduron            #+#    #+#             */
/*   Updated: 2019/05/05 16:21:21 by gduron           ###   ########.fr       */
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

void	playground(void)
{
	size_t	*str;
	t_chunk	*ptr;

	str = (size_t*)ft_malloc(5000);
	str -= 3;
	printf("\nbin headers: |%zu|%zu|%zu|%zu|\n",
		str[0], str[1], str[2], str[3]);
	str = (size_t*)ft_malloc(4566);
	str -= 3;
	printf("bin headers: |%zu|%zu|%zu|%zu|\n", str[0], str[1], str[2], str[3]);
	str = (size_t*)ft_malloc(7770);
	str -= 3;
	printf("bin headers: |%zu|%zu|%zu|%zu|\n", str[0], str[1], str[2], str[3]);
	str = (size_t*)ft_malloc(4064);
	printf("bin headers: |%zu|\n", str[4064 / 8]);
	ptr = (t_chunk*)ft_malloc(5000);
	printf("chunk headers: |%zu|%zu|\n", ptr[-1].prev_size, ptr[-1].size);
	printf("chunk headers: |%zu\n", ptr[(ptr[-1].size / 16)].size);
	show_alloc_mem();
	str = (size_t*)ft_malloc(1);
	str = (size_t*)ft_malloc(16);
	str = (size_t*)ft_malloc(34);
	show_alloc_mem();
	str = (size_t*)ft_malloc(65);
	str = (size_t*)ft_malloc(245);
	str = (size_t*)ft_malloc(1000);
	show_alloc_mem();
}

int		main(void)
{
	playground();
	RUN(test_malloc_zero);
	RUN(test_malloc_large);
	return (TEST_REPORT());
}
