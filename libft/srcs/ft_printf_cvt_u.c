/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cvt_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 18:18:13 by gduron            #+#    #+#             */
/*   Updated: 2017/05/22 12:26:44 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*cvt_u(unsigned long long nbr, char *buf)
{
	char				*p;

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

void			ft_printf_cvt_u(va_list *app, t_flag *flag)
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
	p = cvt_u(nbr > 0 ? nbr : -nbr, buf);
	flag->precision == 0 && *p == '0' ? p = (buf + sizeof(buf)) : 0;
	ft_printf_putd(p, (buf + sizeof(buf)) - p, flag, s_len);
}
