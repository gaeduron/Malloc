/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft_malloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:51:13 by gduron            #+#    #+#             */
/*   Updated: 2019/05/02 20:28:07 by gduron           ###   ########.fr       */
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
		alloc[-1] == size + FIRST_CHUNK_FLAGS);
	ASSERT("MALLOC: bin first chunk flags",
		(alloc[-1] & FIRST_CHUNK_FLAGS) == FIRST_CHUNK_FLAGS);
	last_adr = ((char *)alloc + size);
	ASSERT("MALLOC: is the right size", *last_adr == 0 || *last_adr != 0);
	ASSERT("MALLOC: bin are terminated by a final chunk", *last_adr == 2);
}

void	playground(void)
{
	size_t *str;

	str = (size_t*)ft_malloc(5000);
	str -= 3;
	printf("\nbin headers: |%zu|%zu|%zu|%zu|\n", str[0], str[1], str[2], str[3]);
	str = (size_t*)ft_malloc(4566);
	str -= 3;
	printf("bin headers: |%zu|%zu|%zu|%zu|\n", str[0], str[1], str[2], str[3]);
	str = (size_t*)ft_malloc(7770);
	str -= 3;
	printf("bin headers: |%zu|%zu|%zu|%zu|\n", str[0], str[1], str[2], str[3]);
	str = (size_t*)ft_malloc(4064);
	printf("bin headers: |%zu|\n", str[4064 / 8]);
}

int		main(void)
{
	playground();
	RUN(test_malloc_zero);
	RUN(test_malloc_large);
	return (TEST_REPORT());
}
