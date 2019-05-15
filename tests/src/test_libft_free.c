/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:38:14 by gduron            #+#    #+#             */
/*   Updated: 2019/05/15 18:50:02 by gduron           ###   ########.fr       */
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

void	test_3_tiny_bins(void)
{
	size_t	*ptr[290];
	int		i;
	int		bin_count;
	t_bin	*bin;

	i = 0;
	while (i < 290)
	{
		ptr[i] = (size_t*)ft_malloc(MAX_TINY_CHUNK);
		if (i % 5 == 0)
			ft_free(ptr[i]);
		i++;
	}
	bin = g_zones[TINY];
	bin_count = 0;
	while (bin != 0)
	{
		bin_count++;
		bin = bin->next;
	}
	ASSERT("FREE: TINY zone should contain 3 bins", bin_count == 3);
	i = 0;
	while (i < 290)
	{
		if (i % 5 != 0)
			ft_free(ptr[i]);
		i++;
	}
	ASSERT("FREE: free should work with multiple bins",
		g_zones[TINY] == 0);
}

void	playground(void)
{
	return ;
}

int		main(void)
{
	RUN(test_free_zero);
	RUN(test_free_large);
	RUN(test_free_large_order2);
	RUN(test_multiple_large);
	RUN(test_multiple_tiny);
	RUN(test_3_tiny_bins);
	playground();
	return (TEST_REPORT());
}
