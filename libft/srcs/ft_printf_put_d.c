/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 18:19:14 by gduron            #+#    #+#             */
/*   Updated: 2017/05/22 15:13:36 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	void	ft_put_space(int call, int s_len, int len, t_flag *flag)
{
	if (call == 1)
	{
		while (!flag->flag['-'] && !flag->flag['0'] && flag->space >
				(flag->precision > len ? flag->precision : len) + s_len)
			add_to_buff(flag, ' ');
	}
	else if (call == 2)
	{
		while (flag->flag['-'] && flag->space > 0)
			add_to_buff(flag, ' ');
	}
}

static	void	ft_put_sign(t_flag *flag, int s_len)
{
	if (flag->flag['#'] && s_len)
	{
		add_to_buff(flag, '0');
		flag->id == 'x' || flag->id == 'p' ? add_to_buff(flag, 'x') : 0;
		flag->id == 'X' ? add_to_buff(flag, 'X') : 0;
		flag->id == 'b' ? add_to_buff(flag, 'b') : 0;
		flag->precision >= 0 && flag->id == 'o' ?
			(flag->precision -= s_len) : 0;
	}
	else
	{
		flag->flag[' '] ? add_to_buff(flag, ' ') : 0;
		flag->flag['+'] == 1 ? add_to_buff(flag, '+') : 0;
		flag->flag['+'] == 2 ? add_to_buff(flag, '-') : 0;
	}
}

static	void	ft_put_precision_or_0(t_flag *flag, int len)
{
	if (flag->precision == -1 && flag->flag['0'])
		flag->precision = flag->space;
	while (flag->precision-- > len)
		add_to_buff(flag, '0');
}

static	void	ft_put_value(t_flag *flag, char *p)
{
	if (flag->id == 'c')
		add_to_buff(flag, *p++);
	while (*p)
		add_to_buff(flag, *p++);
}

void			ft_printf_putd(char *p, int len, t_flag *flag, int s_len)
{
	flag->space ? ft_put_space(1, s_len, len, flag) : 0;
	s_len ? ft_put_sign(flag, s_len) : 0;
	ft_put_precision_or_0(flag, len);
	ft_put_value(flag, p);
	flag->space > 0 ? ft_put_space(2, s_len, len, flag) : 0;
}
