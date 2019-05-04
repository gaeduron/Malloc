/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 16:58:13 by gduron            #+#    #+#             */
/*   Updated: 2017/04/14 10:07:19 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;
	void	*content_cpy;

	if (!(node = (t_list*)malloc(sizeof(t_list))))
		return (0);
	if (content == 0)
	{
		node->content = 0;
		node->content_size = 0;
	}
	else
	{
		if (!(content_cpy = (void*)malloc(content_size)))
			return (0);
		node->content = ft_memcpy(content_cpy, content, content_size);
		node->content_size = content_size;
	}
	node->next = 0;
	return (node);
}
