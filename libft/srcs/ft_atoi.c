/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 10:46:30 by gduron            #+#    #+#             */
/*   Updated: 2017/05/31 13:57:10 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	if (c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	long	nbr;
	int		pos;

	pos = 1;
	nbr = 0;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			pos = -1;
		}
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10;
		nbr = nbr + (*str - '0');
		str++;
	}
	nbr = nbr * pos;
	return ((int)nbr);
}
