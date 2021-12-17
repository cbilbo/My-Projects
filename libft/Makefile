# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/10 21:22:34 by cbilbo            #+#    #+#              #
#    Updated: 2021/12/17 19:50:01 by cbilbo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = $(wildcard char/*.c) $(wildcard d_link/*.c) $(wildcard ft_printf/*.c) \
	$(wildcard lists/*.c) $(wildcard memory/*.c) $(wildcard numbers/*.c) \
	$(wildcard print/*.c) $(wildcard string/*.c) $(wildcard utils/*.c)

OBJS = $(patsubst %.c,$(O_DIR)%.o,$(SRCS))
O_DIR = objs/

DIR_O = @mkdir -p objs/	objs/char/ objs/d_link/ objs/ft_printf/ objs/lists/ \
		objs/memory/ objs/numbers/ objs/print/ objs/string/ objs/utils/ 

CC = gcc
CFLAGS = -Wall -Wextra -Werror -MMD -O2
RM = rm -rf
MLB = ar -rcs

all:
	@echo Create libft
	@$(MAKE) -s -j4 $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@$(MLB) $(NAME) $(OBJS)
	@echo '√'
	@echo Libft created!

$(O_DIR)%.o: %.c
	$(DIR_O)
	@echo -n '#'
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo Objectives deleted
	@$(RM) $(O_DIR)

fclean: clean
	@$(RM) $(NAME)
	@echo Libft deleted

re: fclean all

.PHONY: all clean fclean re