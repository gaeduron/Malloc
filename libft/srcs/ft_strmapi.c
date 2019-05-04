/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 09:25:11 by gduron            #+#    #+#             */
/*   Updated: 2017/04/13 16:11:27 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	long	i;

	i = 0;
	if (!(new = ft_strdup(s)))
		return (0);
	while (new[i])
	{
		new[i] = f(i, s[i]);
		i++;
	}
	return (new);
}
