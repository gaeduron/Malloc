/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cvt_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 18:18:13 by gduron            #+#    #+#             */
/*   Updated: 2017/05/22 15:25:08 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	char	*cvt_b(unsigned long long nbr, char *buf, t_flag *flag)
{
	char	*p;
	int		i;

	i = 1;
	p = buf + 44;
	*p = 0;
	if (nbr == 0)
		*--p = '0';
	while (nbr)
	{
		*--p = nbr % 2 + '0';
		!(i++ % 4) && flag->flag['#'] && nbr / 2 ? *--p = '-' : 0;
		nbr /= 2;
	}
	return (p);
}

void			ft_printf_cvt_b(va_list *app, t_flag *flag)
{
	unsigned long long		nbr;
	char					buf[80];
	char					*p;
	int						s_len;

	s_len = 0;
	nbr = 0;
	nbr = ft_printf_get_arg(app, flag);
	nbr = (flag->flag['l'] || flag->flag['L'] || flag->flag['z'] ||
			flag->flag['j']) ? nbr : (unsigned int)nbr;
	p = cvt_b(nbr > 0 ? nbr : -nbr, buf, flag);
	s_len = flag->flag['#'] ? 2 : 0;
	s_len = *p == '0' && flag->id != 'p' ? 0 : s_len;
	flag->precision == 0 && *p == '0' ? p = (buf + sizeof(buf)) : 0;
	ft_printf_putd(p, (buf + sizeof(buf)) - p, flag, s_len);
}
