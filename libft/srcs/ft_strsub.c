/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 09:41:05 by gduron            #+#    #+#             */
/*   Updated: 2017/04/13 11:06:01 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*dup;
	unsigned int	i;

	i = start;
	if (!(dup = (char*)malloc(sizeof(char) * (len) + 1)))
		return (0);
	while (i < (unsigned int)len + start)
	{
		dup[i - start] = s[i];
		i++;
	}
	dup[i - start] = '\0';
	return (dup);
}
