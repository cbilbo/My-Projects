# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/14 18:21:53 by cbilbo            #+#    #+#              #
#    Updated: 2021/09/17 18:18:18 by cbilbo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
NAME2 = client
NAME_BONUS = server_bonus
NAME2_BONUS = client_bonus
SRCS_DIR = ./srcs
OBJS_DIR = ./objs
INC_DIR = ./include
LIB_DIR = ./libft

SRCS_S = server.c
SRCS_C = client.c

SRCS_B_S = server_bonus.c
SRCS_B_C = client_bonus.c

OBJS_S = $(addprefix $(OBJS_DIR)/,$(SRCS_S:.c=.o))
OBJS_C = $(addprefix $(OBJS_DIR)/,$(SRCS_C:.c=.o))
OBJS_B_S = $(addprefix $(OBJS_DIR)/,$(SRCS_B_S:.c=.o))
OBJS_B_C = $(addprefix $(OBJS_DIR)/,$(SRCS_B_C:.c=.o))

HEADER = include/minitalk.h
HEADER_B = include/minitalk_bonus.h
LIB = ./libft/libft.a

CC = gcc
FLAGS = -g -Wall -Werror -Wextra
RM = rm -rf

all: libft $(NAME) $(NAME2) 

$(NAME): $(OBJS_S) $(HEADER)
	$(CC) $(FLAGS) $(OBJS_S) $(LIB) -o $(NAME)

$(NAME2): $(OBJS_C) $(HEADER)
	$(CC) $(FLAGS) $(OBJS_C) $(LIB) -o $(NAME2)

$(NAME_BONUS): $(OBJS_B_S) $(HEADER_B)
	$(CC) $(FLAGS) $(OBJS_B_S) $(LIB) -o $(NAME_BONUS)

$(NAME2_BONUS): $(OBJS_B_C) $(HEADER) $(HEADER_B)
	$(CC) $(FLAGS) $(OBJS_B_C) $(LIB) -o $(NAME2_BONUS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER) $(HEADER_B)
	mkdir -p $(OBJS_DIR)
	$(CC) $(FLAGS) -I $(LIB_DIR) -c $< -o $@

.c.o:
	$(CC) $(FLAGS) -I $(INC_DIR) -c $< -o $(<:.c=.o)

bonus: libft $(NAME_BONUS) $(NAME2_BONUS)

rebonus: fclean bonus

libft:
	$(MAKE) -C $(LIB_DIR)

clean:
	$(MAKE) clean -C $(LIB_DIR)
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(LIB) $(NAME) $(NAME2) $(NAME_BONUS) $(NAME2_BONUS)

re: fclean all
.PHONY: all clean fclean re libft bonus rebonus