/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:54:51 by gduron            #+#    #+#             */
/*   Updated: 2017/04/14 10:47:29 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		ft_list_size(t_list *begin_list)
{
	unsigned int i;

	i = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}

t_list					*ft_lst_at(t_list *begin_list, unsigned int nbr)
{
	if (nbr > ft_list_size(begin_list))
		return (0);
	while (nbr--)
		begin_list = begin_list->next;
	return (begin_list);
}
