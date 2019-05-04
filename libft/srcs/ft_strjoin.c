/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 10:10:14 by gduron            #+#    #+#             */
/*   Updated: 2017/04/13 13:14:48 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_len;
	char	*tmp;
	int		i;

	i = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	if ((tmp = (char *)malloc(sizeof(char) * (total_len + 1))) == NULL)
		return (0);
	tmp[total_len] = '\0';
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	while (*s2)
		tmp[i++] = *s2++;
	return (tmp);
}
