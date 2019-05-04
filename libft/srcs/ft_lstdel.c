/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:19:27 by gduron            #+#    #+#             */
/*   Updated: 2017/04/13 18:25:29 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *head;
	t_list *tmp;

	head = *alst;
	tmp = head;
	while (head)
	{
		tmp = tmp->next;
		ft_lstdelone(&head, del);
		head = tmp;
	}
	*alst = 0;
}
