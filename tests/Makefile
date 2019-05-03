# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gduron <gduron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/31 12:27:06 by gduron            #+#    #+#              #
#    Updated: 2019/05/03 14:46:06 by gduron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            := malloc_tests

CC              := gcc
FLAGS           := -Wall -Wextra -Werror -fsanitize=address
LIB				:= ft_malloc
STATICLIB		:= ft_malloc_static

SRCS_PATH		:= ./src

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME):
	@echo "$(LIB_PATH)"
	@$(CC) $(FLAGS) -o print_page_size $(SRCS_PATH)/print_page_size.c
	@$(CC) $(FLAGS) -o test_no_malloc $(SRCS_PATH)/test_no_malloc.c
	@$(CC) $(FLAGS) -o test_official_malloc  $(SRCS_PATH)/test_official_malloc.c
	@$(CC) $(FLAGS) -o test_libft_malloc  $(SRCS_PATH)/test_libft_malloc.c -L.. -l$(STATICLIB)
	@$(CC) $(FLAGS) -o test_libft_free  $(SRCS_PATH)/test_libft_free.c -L.. -l$(STATICLIB)
	@echo "Malloc Tests:\033[92m Created\033[0m"

clean:
	@echo "Cleaning:\033[33m *.o\033[0m"

fclean: clean
	@echo "Cleaning:\033[33m $(NAME)\033[0m"
	@rm -f print_page_size test_no_malloc test_official_malloc test_libft_malloc test_libft_free ./includes/tinytest.h.gch

re: fclean all

test: all
	@sh ./run_tests.sh
