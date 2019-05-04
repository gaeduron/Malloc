/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 11:07:48 by gduron            #+#    #+#             */
/*   Updated: 2017/05/22 13:44:43 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	void	ft_put_space(int call, t_flag *flag)
{
	if (call == 1)
	{
		while (!flag->flag['-'] && !flag->flag['0'] && flag->space >
				flag->precision)
			add_to_buff(flag, ' ');
	}
	if (call == 2)
	{
		while (flag->flag['-'] && flag->space > 0)
			add_to_buff(flag, ' ');
	}
}

static	void	ft_put_precision_or_0(t_flag *flag, int len)
{
	while (flag->precision > len && flag->flag['0'])
	{
		add_to_buff(flag, '0');
		flag->precision--;
	}
}

static	void	ft_put_value(t_flag *flag, char *p)
{
	while (*p && (flag->flag['.'] ? flag->precision-- : 1))
		add_to_buff(flag, *p++);
}

void			ft_printf_puts(char *p, int len, t_flag *flag)
{
	ft_put_space(1, flag);
	ft_put_precision_or_0(flag, len);
	ft_put_value(flag, p);
	ft_put_space(2, flag);
}
