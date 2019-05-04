/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:22:05 by gduron            #+#    #+#             */
/*   Updated: 2017/04/11 11:45:21 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *big, const char *little)
{
	int i;

	i = 0;
	if (!little[i])
		return ((char *)big);
	while (*big)
	{
		i = 0;
		while (little[i] == big[i] && little[i] && big[i])
		{
			if (little[i + 1] == '\0')
				return ((char *)big);
			i++;
		}
		big++;
	}
	return (0);
}
