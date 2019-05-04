/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_and_print.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 18:28:01 by gduron            #+#    #+#             */
/*   Updated: 2017/05/22 17:00:14 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	add_to_buff(t_flag *flag, char c)
{
	if (flag->i == BUFFSIZE)
	{
		write(1, flag->buff, flag->i);
		flag->i = 0;
	}
	flag->buff[flag->i] = c;
	flag->i++;
	flag->space--;
	flag->printed_char++;
}

void	fmt_print(t_flag *flag, const char *fmt)
{
	void (*fun_ptr)(va_list *app, struct s_flag *flag);

	flag->i = 0;
	while (*fmt && flag->printed_char >= 0)
	{
		if (*fmt != '%' || *(++fmt) == '%')
			add_to_buff(flag, *fmt++);
		else
		{
			if (flag->init == 0)
				init_flag(flag);
			reset_flag(flag);
			get_flags(flag, &fmt);
			fun_ptr = flag->cvt[flag->id];
			if (flag->cvt[flag->id])
				fun_ptr(&(flag->ap), flag);
			else
				fmt--;
		}
	}
	write(1, flag->buff, flag->i);
	flag->i = 0;
}
