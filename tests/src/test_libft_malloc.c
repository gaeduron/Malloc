/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft_malloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:51:13 by gduron            #+#    #+#             */
/*   Updated: 2019/05/02 16:03:39 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../includes/libft_malloc.h"

int		main(void)
{
	void	*bin;

	bin = 0;
	bin = (void*)ft_malloc(5000);
	printf("%p", bin);
	return (0);
}
