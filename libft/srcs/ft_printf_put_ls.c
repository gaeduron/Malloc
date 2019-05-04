/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_ls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 18:19:14 by gduron            #+#    #+#             */
/*   Updated: 2017/05/22 17:30:24 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	size_t	wsize(wchar_t c, size_t u_fmt, int get_mask)
{
	if (MB_CUR_MAX == 1 && c > 0xff)
	{
		return (0x100);
	}
	if (get_mask)
	{
		u_fmt = c <= 0x1FFFFF ? 0b11110000100000001000000010000000 : u_fmt;
		u_fmt = c <= 0xFFFF ? 0b111000001000000010000000 : u_fmt;
		u_fmt = c <= 0x7FF ? 0b1100000010000000 : u_fmt;
		u_fmt = c <= 0x7F ? 0b00000000 : u_fmt;
		return (u_fmt);
	}
	else
	{
		u_fmt = c <= 0x1FFFFF ? 4 : u_fmt;
		u_fmt = c <= 0xFFFF ? 3 : u_fmt;
		u_fmt = c <= 0x7FF ? 2 : u_fmt;
		u_fmt = c <= 0x7F ? 1 : u_fmt;
	}
	return (u_fmt);
}

static	size_t	put_wchar(t_flag *flag, wchar_t c)
{
	size_t		u_fmt;
	size_t		tmp_mask;
	int			nboctet;
	int			c_tmp;

	u_fmt = 0;
	nboctet = 1;
	u_fmt = wsize(MB_CUR_MAX == 1 ? (char)c : c, u_fmt, 1);
	c_tmp = (int)wsize(MB_CUR_MAX == 1 && c <= 0xff ? (char)c : c, 1, 0);
	while (c)
	{
		tmp_mask = u_fmt ? c & 0b00111111 : c;
		tmp_mask <<= 8 * (nboctet - 1);
		u_fmt = tmp_mask | u_fmt;
		c = (size_t)c == u_fmt ? c >> 7 : c >> 6;
		nboctet = c ? nboctet + 1 : nboctet;
	}
	nboctet = c_tmp;
	while (nboctet && nboctet != 0x100)
	{
		if (flag->precision-- > 0)
			add_to_buff(flag, (char)(u_fmt >> (8 * (nboctet - 1))));
		nboctet--;
	}
	return (nboctet);
}

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

static	size_t	ft_put_value(t_flag *flag, wchar_t *p)
{
	size_t	ret;

	ret = 0;
	if (flag->id == 'C')
		ret = put_wchar(flag, *p++);
	while (*p != L'\0')
	{
		if (ret == 0x100)
			return (ret);
		ret = put_wchar(flag, *p++);
	}
	return (ret);
}

void			ft_printf_putls(wchar_t *p, int len, t_flag *flag)
{
	flag->space ? ft_put_space(1, 0, len, flag) : 0;
	if (ft_put_value(flag, p) == 0x100)
	{
		flag->printed_char = -1;
		flag->i--;
		return ;
	}
	flag->space > 0 ? ft_put_space(2, 0, len, flag) : 0;
}
