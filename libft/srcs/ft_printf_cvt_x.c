/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cvt_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 18:18:13 by gduron            #+#    #+#             */
/*   Updated: 2017/05/22 13:05:28 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	char	*cvt_x(unsigned long long nbr, char *buf)
{
	char	*p;

	p = buf + 44;
	*p = 0;
	if (nbr == 0)
		*--p = '0';
	while (nbr)
	{
		*--p = nbr % 16 > 9 ? nbr % 16 + 'a' - 10 : nbr % 16 + '0';
		nbr /= 16;
	}
	return (p);
}

static	char	*cvt_lx(unsigned long long nbr, char *buf)
{
	char	*p;

	p = buf + 44;
	*p = 0;
	if (nbr == 0)
		*--p = '0';
	while (nbr)
	{
		*--p = nbr % 16 > 9 ? nbr % 16 + 'A' - 10 : nbr % 16 + '0';
		nbr /= 16;
	}
	return (p);
}

void			ft_printf_cvt_x(va_list *app, t_flag *flag)
{
	unsigned long long		nbr;
	char					buf[44];
	char					*p;
	int						s_len;

	s_len = 0;
	nbr = 0;
	nbr = ft_printf_get_arg(app, flag);
	nbr = (flag->flag['l'] || flag->flag['L'] || flag->flag['z'] ||
			flag->flag['j']) ? nbr : (unsigned int)nbr;
	if (flag->id == 'x' || flag->id == 'p')
		p = cvt_x(nbr > 0 ? nbr : -nbr, buf);
	else
		p = cvt_lx(nbr > 0 ? nbr : -nbr, buf);
	s_len = flag->flag['#'] ? 2 : 0;
	s_len = *p == '0' && flag->id != 'p' ? 0 : s_len;
	flag->precision == 0 && *p == '0' ? p = (buf + sizeof(buf)) : 0;
	ft_printf_putd(p, (buf + sizeof(buf)) - p, flag, s_len);
}
