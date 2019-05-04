# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gduron <gduron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/31 12:27:06 by gduron            #+#    #+#              #
#    Updated: 2019/05/04 15:29:43 by gduron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            := libft_malloc.so

ifeq ($(HOSTTYPE),)
HOSTTYPE 		:= $(shell uname -m)_$(shell uname -s)
endif
FULLNAME		:= libft_malloc_$(HOSTTYPE).so
STATICNAME		:= libft_malloc_static.a

CC              := gcc
FLAGS           := -Wall -Wextra -Werror -g

SRCS_FILES      :=  libft_malloc.c\
					libft_free.c\
					show_alloc_mem.c\


HEADERS_FILES   :=  libft_malloc.h\

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

.PHONY: all libft clean fclean re

all: libft $(NAME)

libft:
	@make -C $(LIBFT_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(HEADERS) $(LIBFT_PATH)/libft.a
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) $(INCLUDES) $(LIBFT_INCLUDES) -o $@ -c $<

$(NAME): $(OBJS)
	@$(CC) -shared $(OBJS) -o $(FULLNAME) $(LIBFT)
	@ln -fs $(FULLNAME) $@
	@echo "$(NAME):\033[92m linked\033[0m"

clean:
	@echo "Cleaning:\033[33m *.o\033[0m"
	@rm -f $(OBJS)
	@rmdir $(OBJS_PATH) 2> /dev/null || true
	@make -C $(LIBFT_PATH) clean

fclean: clean
	@echo "Cleaning:\033[33m $(NAME)\033[0m"
	@make fclean -C ./tests
	@make fclean -C $(LIBFT_PATH)
	@rm -f $(NAME) ${FULLNAME} $(STATICNAME)

re: fclean all

test: all
	@ar rc $(STATICNAME) $(LIBFT_PATH)objs/*.o $(OBJS)
	@ranlib $(STATICNAME)
	@make test -C ./tests