/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 11:18:24 by gduron            #+#    #+#             */
/*   Updated: 2017/05/22 15:33:02 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# define BUFFSIZE 3477594

typedef struct	s_flag
{
	char		flag[128];
	char		buff[BUFFSIZE];
	int			id;
	int			i;
	int			init;
	int			space;
	int			precision;
	void		*cvt[128];
	va_list		ap;
	long long	printed_char;
}				t_flag;

int				ft_printf(const char *format, ...);
void			fmt_print(t_flag *flag, const char *fmt);
void			init_flag(t_flag *flag);
void			reset_flag(t_flag *flag);
void			get_flags(t_flag *flag, const char **fmt);
void			add_to_buff(t_flag *flag, char c);
long long		ft_printf_get_arg(va_list *app, t_flag *flag);

void			ft_printf_cvt_d(va_list *app, t_flag *flag);
void			ft_printf_cvt_o(va_list *app, t_flag *flag);
void			ft_printf_cvt_u(va_list *app, t_flag *flag);
void			ft_printf_cvt_x(va_list *app, t_flag *flag);
void			ft_printf_cvt_c(va_list *app, t_flag *flag);
void			ft_printf_cvt_lc(va_list *app, t_flag *flag);
void			ft_printf_cvt_p(va_list *app, t_flag *flag);
void			ft_printf_cvt_s(va_list *app, t_flag *flag);
void			ft_printf_cvt_ls(va_list *app, t_flag *flag);
void			ft_printf_cvt_pourcent(va_list *app, t_flag *flag);
void			ft_printf_cvt_b(va_list *app, t_flag *flag);

void			ft_printf_putd(char *p, int len, t_flag *flag, int s_len);
void			ft_printf_puts(char *p, int len, t_flag *flag);
void			ft_printf_putls(wchar_t *p, int len, t_flag *flag);
#endif
