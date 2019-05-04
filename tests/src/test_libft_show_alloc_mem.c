/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft_show_alloc_mem.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:42:53 by gduron            #+#    #+#             */
/*   Updated: 2019/05/04 19:05:38 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft_malloc.h"

void	playground(void)
{
	void	*ptr;
	void	*ptr2;
	void	*ptr3;
	void	*ptr4;
	void	*ptr5;

	ft_printf("Before allocation:\n");
	show_alloc_mem();

	ptr = ft_malloc(5000);
	ft_printf("After one allocation:\n");
	show_alloc_mem();

	ft_printf("After 4 more allocation:\n");
	ptr2 = ft_malloc(5003);
	ptr3 = ft_malloc(8111);
	ptr4 = ft_malloc(9235);
	ptr5 = ft_malloc(1234);
	show_alloc_mem();

	ft_printf("After 1 free:\n");
	ft_free(ptr3);
	show_alloc_mem();

	ft_printf("After free, only one left:\n");
	ft_free(ptr5);
	ft_free(ptr);
	ft_free(ptr2);
	show_alloc_mem();

	ft_printf("After everything is free:\n");
	ft_free(ptr4);
	show_alloc_mem();
}

int		main(void)
{
	playground();
	return (0);
}
