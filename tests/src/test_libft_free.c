/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:38:14 by gduron            #+#    #+#             */
/*   Updated: 2019/05/05 20:23:23 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/tinytest.h"
#include "../../includes/libft_malloc.h"

void	test_free_zero(void)
{
	ASSERT("FREE: should handle zero", ft_free(0) == 2);
}

void	test_free_large(void)
{
	t_chunk	*ptr;
	char	*str;
	int		*tab;

	ptr = (t_chunk*)ft_malloc(5000);
	str = (char*)ft_malloc(2000);
	tab = (int*)ft_malloc(6500);
	ASSERT("FREE: should free large allocations",
		ft_free(ptr) == 1);
	ASSERT("FREE: should be able to free after a free in the same zone",
		ft_free(str) == 1);
	ASSERT("FREE: should be able to free the last bin in the zone",
		ft_free(tab) == 1);
	ASSERT("FREE: g_zones[LARGE]\
		should be empty after every bin has been freed",
		g_zones[LARGE] == 0);
}

void	test_free_large_order2(void)
{
	char	*str;
	size_t	*ptr;
	int		*tab;

	str = (char*)ft_malloc(2000);
	ptr = (size_t*)ft_malloc(8933);
	tab = (int*)ft_malloc(6500);
	ASSERT("FREE: should free large zone pointer",
		ft_free(ptr) == 1);
	ASSERT("FREE: should work after a free in one of the middle bins",
		ft_free(str) == 1);
	ASSERT("FREE: should work after a free on the last bin",
		ft_free(tab) == 1);
	ASSERT("FREE: g_zones[LARGE]\
		should be empty after every bin has been freed",
		g_zones[LARGE] == 0);
}

void	test_free_large_order3(void)
{
	char	*str;
	size_t	*ptr;
	int		*tab;

	str = (char*)ft_malloc(2000);
	ptr = (size_t*)ft_malloc(8933);
	tab = (int*)ft_malloc(6500);
	ASSERT("FREE: should free large zone pointer",
		ft_free(ptr) == 1);
	ASSERT("FREE: should work after a free in one of the middle bins",
		ft_free(tab) == 1);
	ASSERT("FREE: should work after a free on the first bin",
		ft_free(str) == 1);
	ASSERT("FREE: g_zones[LARGE]\
		should be empty after every bin has been freed",
		g_zones[LARGE] == 0);
}

void	test_multiple_large(void)
{
	size_t	*ptr[4000];
	int		i;

	i = 0;
	while (i < 4000)
	{
		ptr[i] = (size_t*)ft_malloc(i + 1025);
		ASSERT("FREE: Large zone should contain bins when\
			allocating large memory spaces",
			g_zones[LARGE] != 0);
		ft_free(ptr[i]);
		i++;
	}
	ASSERT("FREE: free and malloc should handle multiple large allocation",
		g_zones[LARGE] == 0);
}

void	test_multiple_tiny(void)
{
	size_t	*ptr[64];
	int		i;

	i = 0;
	while (i < 63)
	{
		ptr[i] = (size_t*)ft_malloc(i + 1);
		ASSERT("FREE: TINY zone should contain bins when\
			allocating large memory spaces",
			g_zones[TINY] != 0);
		ft_free(ptr[i]);
		i++;
	}
	ASSERT("FREE: free and malloc should handle multiple large allocation",
		g_zones[TINY] == 0);
}

void	playground(void)
{
	void	*ptr;
	void	*ptr2;
	t_chunk	*chunk;

	ptr = ft_malloc(5000);
	chunk = (t_chunk*)ptr - 1;
	printf("\nsize in t_chunk: %zu\n", (chunk->size / 16));
	printf("last chunk size: %zu\n",
		chunk[(chunk->size / 16) + 1].size);
	printf("last chunk size after AND: %zu\n",
		chunk[(chunk->size / 16) + 1].size & 0b1);
	printf("large zone pointer: %p\n", g_zones[LARGE]);
	ft_free(ptr);
	printf("large zone pointer after free: %p\n", g_zones[LARGE]);
	ptr = ft_malloc(5000);
	chunk = (t_chunk*)ptr - 1;
	ptr2 = ft_malloc(5003);
	ptr2 = ft_malloc(4);
	show_alloc_mem();
	ft_free(ptr2);
	show_alloc_mem();
}

int		main(void)
{
	RUN(test_free_zero);
	RUN(test_free_large);
	RUN(test_free_large_order2);
	RUN(test_multiple_large);
	RUN(test_multiple_tiny);
	playground();
	return (TEST_REPORT());
}
