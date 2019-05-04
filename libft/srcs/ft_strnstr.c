/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:56:21 by gduron            #+#    #+#             */
/*   Updated: 2017/04/11 18:58:34 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int i;

	i = 0;
	if (!little[i])
		return ((char *)big);
	while (*big && len)
	{
		i = 0;
		while (little[i] == big[i] && little[i] && big[i] && (len - i))
		{
			if (little[i + 1] == '\0')
				return ((char *)big);
			i++;
		}
		big++;
		len--;
	}
	return (0);
}
