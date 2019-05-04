/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_malloc.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <gduron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:20:29 by gduron            #+#    #+#             */
/*   Updated: 2019/05/04 20:20:11 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <sys/mman.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

# define MAX_TINY_CHUNK 64
# define MAX_SMALL_CHUNK 1024
# define BIN_HEADERS_SIZE 32
# define LAST_CHUNK_HEADER 0b011
# define LAST_CHUNK_FLAG 0b010
# define FIRST_CHUNK_HEADER 0b101

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

void	*ft_malloc(size_t size);
void    *ft_mmap(size_t size);
void	*set_bin_headers(size_t *memory, size_t size);
void	*find_space(size_t size, int zone);

int		ft_free(void *ptr);
int		free_bin(void *ptr, size_t size);

void	show_alloc_mem(void);

size_t	chunk_remove_flags(size_t size);
#endif
