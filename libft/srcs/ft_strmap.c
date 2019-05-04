/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 09:18:02 by gduron            #+#    #+#             */
/*   Updated: 2017/04/13 11:51:46 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	long	i;

	i = 0;
	if (!(new = ft_strdup(s)))
		return (0);
	while (new[i])
	{
		new[i] = f(s[i]);
		i++;
	}
	return (new);
}
