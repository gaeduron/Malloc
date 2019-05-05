/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft_realloc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 11:24:32 by gduron            #+#    #+#             */
/*   Updated: 2019/05/05 11:47:48 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tinytest.h"
#include "../../includes/libft_malloc.h"

void	test_realloc_same_size(void)
{
	char	*str;

	str = malloc(4000);
	ft_strcpy(str, "REALLOC: the same size");
	ASSERT_STRING_EQUALS("REALLOC: the same size", ft_realloc(str, 4000));
}

void	test_realloc_larger_size(void)
{
	char	*str;

	str = malloc(2000);
	ft_strcpy(str, "REALLOC: larger size");
	ASSERT_STRING_EQUALS("REALLOC: larger size", ft_realloc(str, 4000));
}

/*
** TODO: test with a string exatly the size of the allocation
*/

void	test_realloc_smaller_size(void)
{
	char	*str;

	str = malloc(2000);
	ft_strcpy(str, "REALLOC: smaller size");
	ASSERT_STRING_EQUALS("REALLOC: smaller size", ft_realloc(str, 1500));
}

void	playground(void)
{
	return ;
}

int		main(void)
{
	RUN(test_realloc_same_size);
	RUN(test_realloc_larger_size);
	RUN(test_realloc_smaller_size);
	playground();
	return (TEST_REPORT());
}
