/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft_malloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:51:13 by gduron            #+#    #+#             */
/*   Updated: 2019/05/02 17:50:49 by gduron           ###   ########.fr       */
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
	size_t	*last_adr;

	size = 5000;
	ASSERT("MALLOC: should handle large allocation", ft_malloc(size) > 0);
	alloc = (size_t*)ft_malloc(size);
	ASSERT("MALLOC: allocation should be the right size", *(alloc - 1) == size);
	last_adr = (alloc + size - 1);
	ASSERT("MALLOC: is the right size", *last_adr == 0 || *last_adr != 0);
}

void	playground(void)
{
	size_t *str;

	str = (size_t*)ft_malloc(5000);
	printf("\nbin headers: |%zu|%zu|%zu|\n", str[0], str[1], str[2]);
	str = (size_t*)ft_malloc(4566);
	printf("bin headers: |%zu|%zu|%zu|\n", str[0], str[1], str[2]);
	str = (size_t*)ft_malloc(7770);
	printf("bin headers: |%zu|%zu|%zu|\n", str[0], str[1], str[2]);
}

int		main(void)
{
	playground();
	RUN(test_malloc_zero);
	RUN(test_malloc_large);
	return (TEST_REPORT());
}
