/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:38:14 by gduron            #+#    #+#             */
/*   Updated: 2019/05/03 17:02:38 by gduron           ###   ########.fr       */
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

	ptr = (t_chunk*)ft_malloc(5000);
	ASSERT("FREE: should free large allocations",
		ft_free(ptr) == 1);
}

void	playground(void)
{
	void	*ptr;
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
}

int		main(void)
{
	playground();
	RUN(test_free_zero);
	RUN(test_free_large);
	return (TEST_REPORT());
}
