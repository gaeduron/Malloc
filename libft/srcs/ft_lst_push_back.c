/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 10:38:59 by gduron            #+#    #+#             */
/*   Updated: 2017/04/14 09:28:51 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_push_back(t_list **begin_list, t_list *new)
{
	t_list	*last;

	last = (*begin_list);
	if (last == 0)
	{
		*begin_list = new;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = new;
}
