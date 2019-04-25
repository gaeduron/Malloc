# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gduron <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/31 12:27:06 by gduron            #+#    #+#              #
#    Updated: 2017/06/02 18:06:49 by gduron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            := fractol

CC              := gcc
FLAGS           := -Wall -Wextra -Werror -fsanitize=address

SRCS_FILES      :=  \
					main.c\
					do_fractol.c\
					hook_function.c\
					img_utils.c\
					get_color.c\
					mandelbrot.c\
					julia.c\
					burning_ship.c\


HEADERS_FILES   :=  fractol.h\

SRCS_PATH       := srcs/
SRCS            := $(addprefix $(SRCS_PATH), $(SRCS_FILES))

OBJS_PATH       := objs/
OBJS            := $(addprefix $(OBJS_PATH), $(SRCS_FILES:.c=.o))

INCLUDES_PATH   := includes/
INCLUDES        := -I $(INCLUDES_PATH)
HEADERS         := $(addprefix $(INCLUDES_PATH), $(HEADERS_FILES))

LIBFT_PATH      := libft/
LIBFT_INCLUDES  := -I libft/includes
LIBFT           := -L $(LIBFT_PATH) -lft
MLX_PATH        := minilibx_macos/
MLX_INCLUDES    := -I minilibx_macos/
MLX             := -L $(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
MATH            := -lm

.PHONY: all libft mlx clean fclean re

all: libft mlx $(NAME)

mlx:
	@make -C $(MLX_PATH)

libft:
	@make -C $(LIBFT_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(HEADERS) $(LIBFT_PATH)/libft.a
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) $(INCLUDES) $(LIBFT_INCLUDES) $(MLX_INCLUDES) -o $@ -c $<

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(LIBFT) $(MLX) $(MATH) $(OBJS) -o $@
	@echo "fdf:\033[92m linked\033[0m"

clean:
	@echo "Cleaning:\033[33m *.o\033[0m"
	@make -C $(MLX_PATH) clean
	@make -C $(LIBFT_PATH) clean
	@rm -f $(OBJS)
	@rmdir $(OBJS_PATH) 2> /dev/null || true

fclean: clean
	@echo "Cleaning:\033[33m $(NAME)\033[0m"
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)

re: fclean all
