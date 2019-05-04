/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cvt_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 11:02:51 by gduron            #+#    #+#             */
/*   Updated: 2017/05/22 12:24:52 by gduron           ###   ########.fr       */
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

void		ft_printf_cvt_s(va_list *app, t_flag *flag)
{
	char	*p;
	char	*end;

	p = va_arg(*app, char *);
	end = p;
	if (!p)
	{
		null_pointer_case(flag);
		return ;
	}
	while (*end)
		end++;
	if (flag->precision > end - p || flag->precision < 0)
		flag->precision = end - p;
	p ? ft_printf_puts(p, 0, flag) : 0;
}
