# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gduron <gduron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/31 12:27:06 by gduron            #+#    #+#              #
#    Updated: 2019/05/05 11:41:29 by gduron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            := malloc_tests

CC              := gcc
FLAGS           := -Wall -Wextra -Werror -fsanitize=address -g
LIB				:= ft_malloc
STATICLIB		:= ft_malloc_static

SRCS_PATH		:= ./src

EXECUTABLES		:=	print_page_size\
					test_no_malloc\
					test_official_malloc\
					test_libft_malloc\
					test_libft_free\
					test_libft_realloc\
					test_libft_show_alloc_mem

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME):
	@echo "$(LIB_PATH)"
	@$(CC) $(FLAGS) -o print_page_size $(SRCS_PATH)/print_page_size.c
	@$(CC) $(FLAGS) -o test_no_malloc $(SRCS_PATH)/test_no_malloc.c
	@$(CC) $(FLAGS) -o test_official_malloc  $(SRCS_PATH)/test_official_malloc.c
	@$(CC) $(FLAGS) -o test_libft_malloc  $(SRCS_PATH)/test_libft_malloc.c -L.. -l$(STATICLIB)
	@$(CC) $(FLAGS) -o test_libft_free  $(SRCS_PATH)/test_libft_free.c -L.. -l$(STATICLIB)
	@$(CC) $(FLAGS) -o test_libft_realloc  $(SRCS_PATH)/test_libft_realloc.c -L.. -l$(STATICLIB)
	@$(CC) $(FLAGS) -o test_libft_show_alloc_mem  $(SRCS_PATH)/test_libft_show_alloc_mem.c -L.. -l$(STATICLIB)
	@echo "Malloc Tests:\033[92m Created\033[0m"

clean:
	@echo "Cleaning:\033[33m *.o\033[0m"

fclean: clean
	@echo "Cleaning:\033[33m $(NAME)\033[0m"
	@rm -f $(EXECUTABLES) ./includes/tinytest.h.gch
	@rm -rf ./*.dSYM

re: fclean all

test: all
	@sh ./run_tests.sh
