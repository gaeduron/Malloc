/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:38:14 by gduron            #+#    #+#             */
/*   Updated: 2019/05/03 14:42:59 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/tinytest.h"
#include "../../includes/libft_malloc.h"

void	test_free_zero(void)
{
	ASSERT("FREE: should handle zero", ft_free(0) == 2);
}

// void	test_free_large(void)
// {
// }

// void	playground(void)
// {
// }

int		main(void)
{
	//playground();
	RUN(test_free_zero);
	//RUN(test_free_large);
	return (TEST_REPORT());
}
