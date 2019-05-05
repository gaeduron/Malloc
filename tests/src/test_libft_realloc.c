/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft_realloc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 11:24:32 by gduron            #+#    #+#             */
/*   Updated: 2019/05/05 12:50:21 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tinytest.h"
#include "../../includes/libft_malloc.h"

void	test_realloc_same_size(void)
{
	char	*str;

	str = ft_malloc(4000);
	ft_strcpy(str, "REALLOC: the same size");
	ASSERT_STRING_EQUALS("REALLOC: the same size", ft_realloc(str, 4000));
}

void	test_realloc_larger_size(void)
{
	char	*str;

	str = ft_malloc(2000);
	ft_strcpy(str, "REALLOC: larger size");
	ASSERT_STRING_EQUALS("REALLOC: larger size", ft_realloc(str, 4000));
}

/*
** TODO: test with a string exatly the size of the allocation
*/

void	test_realloc_smaller_size(void)
{
	char	*str;

	str = ft_malloc(2000);
	ft_strcpy(str, "REALLOC: smaller size");
	ASSERT_STRING_EQUALS("REALLOC: smaller size", ft_realloc(str, 1500));
}

void	test_realloc_large_if_necessary(void)
{
	char	*str;
	char	*str_tmp;
	char	*str2;
	char	*str2_tmp;

	str = ft_malloc(2000);
	str_tmp = str;
	str = ft_realloc(str, 3000);
	ASSERT("REALLOC: large chunk can be widden", str == str_tmp);
	str = ft_realloc(str, 8192);
	ASSERT("REALLOC: large chunk are reallocated if necessary",
		str != str_tmp);
	str2 = ft_malloc(4096 - 32);
	str2_tmp = str2;
	str2 = ft_realloc(str2, 4096 - 24);
	ASSERT("REALLOC: a full page allocation can't be widden",
		str2 != str2_tmp);
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
	RUN(test_realloc_large_if_necessary);
	playground();
	return (TEST_REPORT());
}
