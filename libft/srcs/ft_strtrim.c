/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 14:38:00 by gduron            #+#    #+#             */
/*   Updated: 2017/04/14 18:54:07 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				ft_is_space(int c)
{
	return ((c == '\n' || c == '\t' || c == ' ') ? 1 : 0);
}

static unsigned long	find_end(char const *s)
{
	unsigned long last_char;

	if (ft_strlen(s) == 0)
		return (0);
	last_char = ft_strlen(s) - 1;
	while (ft_is_space(s[last_char]))
	{
		if (last_char == 0)
			return (last_char + 1);
		last_char--;
	}
	return (last_char + 1);
}

char					*ft_strtrim(char const *s)
{
	unsigned long	start;
	unsigned long	end;
	char			*new;

	start = 0;
	end = find_end(s);
	while (ft_is_space(s[start]) && s[start])
		start++;
	if (s[start] == 0)
		return (ft_strnew(1));
	if (!(new = ft_strsub(s, (unsigned int)start, (size_t)(end - start))))
		return (0);
	return (new);
}
