# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/19 14:35:38 by cbilbo            #+#    #+#              #
#    Updated: 2021/07/23 17:18:17 by cbilbo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s ft_list_size.s ft_list_push_front.s	ft_list_remove_if.s	ft_list_sort.s ft_atoi_base.s
OBJS = $(patsubst %.s, %.o,$(SRCS))
HEADER = libasm.h

CC = nasm
FLAGS = -f macho64
RM = rm -rf
MLB = ar -rcs

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(MLB) $(NAME) $(OBJS)



%.o: %.s $(HEADER)
	$(CC) $(FLAGS) $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
