# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gduron <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/31 12:40:17 by gduron            #+#    #+#              #
#    Updated: 2017/05/31 14:01:24 by gduron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            := libft.a

CC              := gcc
FLAGS           := -Wall -Wextra -Werror #-fsanitize=address

SRCS_FILES      :=  \
ft_putchar.c \
ft_putstr.c \
ft_putnbr.c \
ft_strcmp.c \
ft_strlen.c \
ft_strncmp.c \
ft_strlen.c \
ft_strdup.c \
ft_strstr.c \
ft_strcat.c \
ft_strncat.c \
ft_strlcat.c \
ft_strcpy.c \
ft_strncpy.c \
ft_strnstr.c \
ft_strchr.c \
ft_strrchr.c \
ft_isalpha.c \
ft_isdigit.c \
ft_isprint.c \
ft_isalnum.c \
ft_isascii.c \
ft_isspace.c \
ft_tolower.c \
ft_toupper.c \
ft_itoa.c \
ft_atoi.c \
ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_memccpy.c \
ft_memmove.c \
ft_memchr.c \
ft_memcmp.c \
ft_putendl.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_memalloc.c \
ft_memdel.c \
ft_strnew.c \
ft_strdel.c \
ft_strclr.c \
ft_striter.c \
ft_striteri.c \
ft_strmap.c \
ft_strmapi.c \
ft_strequ.c \
ft_strnequ.c \
ft_strsub.c \
ft_strjoin.c \
ft_strsplit.c \
ft_strtrim.c \
ft_lstnew.c \
ft_lstdelone.c \
ft_lstdel.c \
ft_lstadd.c \
ft_lstiter.c \
ft_lst_push_back.c \
ft_lstmap.c \
ft_lst_at.c \
ft_lst_size.c \
ft_sqrt.c \
ft_pow.c \
\
ft_printf.c \
ft_printf_format_and_print.c \
ft_printf_get_flag.c \
ft_printf_init_flag.c \
ft_printf_get_arg.c\
ft_printf_put_d.c \
ft_printf_put_ls.c \
ft_printf_cvt_d.c \
ft_printf_cvt_pourcent.c \
ft_printf_cvt_u.c \
ft_printf_cvt_o.c \
ft_printf_cvt_x.c \
ft_printf_cvt_c.c \
ft_printf_cvt_s.c \
ft_printf_put_s.c \
ft_printf_cvt_lc.c \
ft_printf_cvt_ls.c \
ft_printf_cvt_b.c \

HEADERS_FILES   :=  libft.h			\
					libftprintf.h	\

SRCS_PATH       := srcs/
SRCS            := $(addprefix $(SRCS_PATH), $(SRCS_FILES))

OBJS_PATH       := objs/
OBJS            := $(addprefix $(OBJS_PATH), $(SRCS_FILES:.c=.o))

INCLUDES_PATH   := includes/
INCLUDES        := -I $(INCLUDES_PATH)
HEADERS         := $(addprefix $(INCLUDES_PATH), $(HEADERS_FILES))

.PHONY: all clean fclean re compiling_msg

all: $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(HEADERS)
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "libft:\033[92m linked\033[0m"

clean:
	@echo "Cleaning:\033[33m *.o\033[0m"
	@rm -f $(OBJS)
	@rmdir $(OBJS_PATH) 2> /dev/null || true

fclean: clean
	@echo "Cleaning:\033[33m libft.a\033[0m"
	@rm -f $(NAME)

re: fclean all
