/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 19:24:06 by exam              #+#    #+#             */
/*   Updated: 2017/04/14 12:00:26 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*str_intmin(char *str)
{
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	return (str);
}

static int		nbr_len(int nbr)
{
	int res;

	res = 0;
	if (nbr <= 0)
		res++;
	while (nbr)
	{
		nbr = nbr / 10;
		res++;
	}
	return (res);
}

static char		*pos_tostr(int nbr, char *str, int i)
{
	while (i >= 0)
	{
		str[i--] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (str);
}

static char		*neg_tostr(int nbr, char *str, int i)
{
	if (nbr == -2147483648)
		return (str_intmin(str));
	nbr = nbr * -1;
	while (i > 0)
	{
		str[i--] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	str[0] = '-';
	return (str);
}

char			*ft_itoa(int nbr)
{
	char	*str;
	int		i;

	i = nbr_len(nbr);
	if ((str = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (0);
	if (nbr == 0)
	{
		str[0] = '0';
		str[1] = 0;
		return (str);
	}
	str[i--] = 0;
	return (nbr > 0 ? pos_tostr(nbr, str, i) : neg_tostr(nbr, str, i));
}
