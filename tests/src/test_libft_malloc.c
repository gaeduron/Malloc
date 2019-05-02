/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft_malloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:51:13 by gduron            #+#    #+#             */
/*   Updated: 2019/05/02 17:07:23 by gduron           ###   ########.fr       */
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
	ASSERT("MALLOC: should handle large allocation", ft_malloc(5000) > 0);
}

int		main(void)
{
	RUN(test_malloc_zero);
	RUN(test_malloc_large);
	return (TEST_REPORT());
}
