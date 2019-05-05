/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft_realloc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 11:24:32 by gduron            #+#    #+#             */
/*   Updated: 2019/05/05 11:38:58 by gduron           ###   ########.fr       */
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

void	playground(void)
{
	return ;
}

int		main(void)
{
	RUN(test_realloc_same_size);
	playground();
	return (TEST_REPORT());
}
