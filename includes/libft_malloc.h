/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_malloc.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:20:29 by gduron            #+#    #+#             */
/*   Updated: 2019/05/01 17:02:19 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <sys/mman.h>
# include <unistd.h>

# define MAX_TINY_CHUNK 64
# define MAX_SMALL_CHUNK 1024

typedef struct		s_chunk
{
	size_t	prev_size;
	size_t	size;
}					t_chunk;

typedef struct		s_bin
{
	struct s_bin	*last;
	struct s_bin	*next;
}					t_bin;

typedef enum        e_zone
{
    TINY,
    SMALL,
    LARGE,
    MAX_ZONE
}                   t_zone;

extern t_bin        *g_zones[MAX_ZONE];

void	*malloc(size_t size);
void    *ft_mmap(size_t size);
void	*set_bin_headers(void *memory, size_t size);
void	*find_space(size_t size, int zone);
#endif
