# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/10 21:22:34 by cbilbo            #+#    #+#              #
#    Updated: 2021/01/30 12:41:51 by cbilbo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
		ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c ft_memccpy.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
		ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_split.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strncmp.c \
		ft_putchar_nbr.c ft_putstr_nbr.c ft_strlen_until.c ft_putstrl.c ft_putcharl.c \
		ft_nbrlen.c

BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
			ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJS	= $(patsubst %.c,%.o,$(SRCS))

BONUS_OBJS = $(patsubst %.c,%.o,$(BONUS))
HEADERS = libft.h

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM =  rm -rf
MLB = ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	@$(MLB) $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS) $(BONUS_OBJS)
 
fclean: clean
	@rm -rf $(NAME)

re: fclean all

bonus: $(OBJS) $(BONUS_OBJS)
		@$(MLB) $(NAME) $(OBJS) $(BONUS_OBJS)
		
.PHONY: all clean fclean re bonus
