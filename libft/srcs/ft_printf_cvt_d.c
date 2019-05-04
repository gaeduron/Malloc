/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cvt_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 18:18:13 by gduron            #+#    #+#             */
/*   Updated: 2017/05/22 13:03:50 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	char	*cvt_d(unsigned long long nbr, char *buf)
{
	char	*p;

	p = buf + 44;
	*p = 0;
	if (nbr == 0)
		*--p = '0';
	while (nbr)
	{
		*--p = nbr % 10 + '0';
		nbr /= 10;
	}
	return (p);
}

void			ft_printf_cvt_d(va_list *app, t_flag *flag)
{
	long long		nbr;
	char			buf[44];
	char			*p;
	int				s_len;

	s_len = 0;
	nbr = 0;
	nbr = ft_printf_get_arg(app, flag);
	nbr = (flag->flag['l'] || flag->flag['L'] || flag->flag['z'] ||
			flag->flag['j']) ? nbr : (int)nbr;
	p = cvt_d(nbr > 0 ? nbr : -nbr, buf);
	if (nbr <= 4294967295 && !(flag->flag['l'] || flag->flag['L'] ||
				flag->flag['z'] || flag->flag['j']))
	{
		(int)nbr < 0 ? flag->flag['+'] = 2 : 0;
		(int)nbr < 0 ? flag->flag[' '] = 0 : 0;
	}
	else
	{
		nbr < 0 ? flag->flag['+'] = 2 : 0;
		nbr < 0 ? flag->flag[' '] = 0 : 0;
	}
	flag->flag['+'] || flag->flag[' '] ? s_len = 1 : 0;
	flag->precision == 0 && *p == '0' ? p = (buf + sizeof(buf)) : 0;
	ft_printf_putd(p, (buf + sizeof(buf)) - p, flag, s_len);
}
