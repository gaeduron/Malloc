/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:39:57 by gduron            #+#    #+#             */
/*   Updated: 2017/04/14 18:42:32 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_len(char const *s, long long *pos, char c)
{
	int i;
	int word_len;

	i = *pos + 1;
	word_len = 1;
	if (!*s)
		return (0);
	while (s[i])
	{
		*pos = i;
		if ((s[i - 1] == c || (i == 1 && s[i - 1] != c))
			&& s[i] != c)
		{
			while (s[*pos] != c && s[*pos])
			{
				*pos = *pos + 1;
				if ((*pos - i) > word_len)
					word_len = *pos - i;
			}
			return (word_len);
		}
		i++;
	}
	return (0);
}

static int		count_word(char const *s, char c)
{
	int i;
	int word_count;

	i = 1;
	word_count = 0;
	if (!*s)
		return (0);
	while (s[i])
	{
		if (s[i - 1] != c && s[i] == c)
		{
			word_count++;
		}
		i++;
	}
	if (i > 0 && s[i - 1] != c)
	{
		word_count++;
	}
	return (word_count);
}

static char		**create_table(int word_count, char const *s, char c)
{
	int			i;
	char		**word_table;
	long long	pos[1];
	long long	len;

	*pos = 0;
	i = 0;
	word_table = 0;
	if ((word_table = (char**)malloc(sizeof(char*) * (word_count + 1))) == NULL)
		return (NULL);
	while (i < word_count)
	{
		len = word_len(s, pos, c);
		if (!(word_table[i] = ft_strnew(len + 1)))
		{
			while (i-- >= 0)
				free(word_table[i]);
			free(word_table);
			return (0);
		}
		word_table[i][len] = 0;
		i++;
	}
	word_table[i] = 0;
	return (word_table);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		x;
	int		y;
	char	**word_table;

	i = 0;
	x = 0;
	if (!(word_table = create_table(count_word(s, c), s, c)))
		return (0);
	while (s[i])
	{
		y = 0;
		while (s[i] != c && s[i])
		{
			word_table[x][y++] = s[i++];
			if (s[i] == c)
				x++;
		}
		if (s[i] == c)
			i++;
	}
	return (word_table);
}
