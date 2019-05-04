/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cvt_ls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 11:02:51 by gduron            #+#    #+#             */
/*   Updated: 2017/05/22 13:05:06 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	null_pointer_case(t_flag *flag)
{
	add_to_buff(flag, '(');
	add_to_buff(flag, 'n');
	add_to_buff(flag, 'u');
	add_to_buff(flag, 'l');
	add_to_buff(flag, 'l');
	add_to_buff(flag, ')');
}

static int	wstrlen(wchar_t *p)
{
	long	i;

	i = 0;
	while (*p)
	{
		i += 4;
		i = *p <= 0xFFFF ? i - 1 : i;
		i = *p <= 0x7FF ? i - 1 : i;
		i = *p <= 0x7F ? i - 1 : i;
		p++;
	}
	return (i);
}

void		ft_printf_cvt_ls(va_list *app, t_flag *flag)
{
	wchar_t	*p;
	int		len;

	p = va_arg(*app, wchar_t *);
	if (!p)
	{
		null_pointer_case(flag);
		return ;
	}
	len = wstrlen(p);
	if (flag->precision > len || flag->precision < 0)
		flag->precision = len;
	p ? ft_printf_putls(p, 0, flag) : 0;
}
