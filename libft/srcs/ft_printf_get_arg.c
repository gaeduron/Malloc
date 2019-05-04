/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 13:51:18 by gduron            #+#    #+#             */
/*   Updated: 2017/05/22 13:10:10 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long long	get_unsigned(va_list *ap, t_flag *flag)
{
	if (flag->flag['z'])
		return (va_arg(*ap, size_t));
	if (flag->flag['j'])
		return (va_arg(*ap, uintmax_t));
	if (flag->flag['L'])
		return (va_arg(*ap, unsigned long long));
	if (flag->flag['l'])
	{
		return (flag->id == 'c' ? va_arg(*ap, wchar_t)
				: va_arg(*ap, unsigned long));
	}
	if (flag->flag['h'])
		return ((unsigned short)va_arg(*ap, unsigned int) & 4294967295);
	if (flag->flag['H'])
		return ((unsigned char)va_arg(*ap, unsigned int) & 4294967295);
	return (va_arg(*ap, unsigned int) & 4294967295);
}

long long	ft_printf_get_arg(va_list *ap, t_flag *flag)
{
	if (flag->id == 'o' || flag->id == 'x' || flag->id == 'X' ||
			flag->id == 'u')
		return (get_unsigned(ap, flag));
	else
	{
		if (flag->flag['z'])
			return (va_arg(*ap, size_t));
		if (flag->flag['j'])
			return (va_arg(*ap, intmax_t));
		if (flag->flag['L'])
			return (va_arg(*ap, long long));
		if (flag->flag['l'])
			return (va_arg(*ap, long));
		if (flag->flag['h'])
			return ((short)va_arg(*ap, int) & 4294967295);
		if (flag->flag['H'])
			return ((signed char)va_arg(*ap, int) & 4294967295);
	}
	return (va_arg(*ap, int) & 4294967295);
}
