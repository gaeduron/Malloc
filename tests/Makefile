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

NAME            := malloc_tests

CC              := gcc
FLAGS           := -Wall -Wextra -Werror -fsanitize=address

SRCS_PATH		:= ./src

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -o print_page_size $(SRCS_PATH)/print_page_size.c
	@$(CC) $(FLAGS) -o test_no_malloc $(SRCS_PATH)/test_no_malloc.c
	@$(CC) $(FLAGS) -o test_official_malloc  $(SRCS_PATH)/test_official_malloc.c
	@echo "Malloc Tests:\033[92m Created\033[0m"
	@sh ./run_tests.sh

clean:
	@echo "Cleaning:\033[33m *.o\033[0m"

fclean: clean
	@echo "Cleaning:\033[33m $(NAME)\033[0m"
	@rm print_page_size test_no_malloc test_official_malloc

re: fclean all

test:
	@sh ./run_tests.sh
