/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 11:16:27 by gduron            #+#    #+#             */
/*   Updated: 2017/05/15 17:44:45 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *format, ...)
{
	static t_flag flag;

	flag.printed_char = 0;
	va_start(flag.ap, format);
	fmt_print(&flag, format);
	va_end(flag.ap);
	return (flag.printed_char);
}
