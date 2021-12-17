# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/22 17:13:21 by cbilbo            #+#    #+#              #
#    Updated: 2021/01/30 12:42:29 by cbilbo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

NAME_LIBFT = libft.a

SRCS = ft_printf.c ft_output_c.c ft_output_s.c ft_output_nbr.c ft_parcer.c \
			ft_start_prf.c ft_fill_prf.c ft_nbrminus_prf.c ft_putnbr_base_prf.c \
			ft_nbrlen_prf.c

OBJS = ${SRCS:.c=.o}

GCC = gcc

CFLAGS = -Wall -Wextra -Werror

MLB = ar rcs

RM = rm -rf

LIBFT_DIR = ./libft/

.c.o:
		@${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			@echo ============ COMPILING LIBFT ============
			@make -C $(LIBFT_DIR)
			@echo ========= COMPILING LIBFTPRINTF =========
			@cp $(LIBFT_DIR)libft.a ./
			@mv $(NAME_LIBFT) $(NAME)
			@$(MLB) $(NAME) ${OBJS}
			@echo ================== DONE =================

all:	${NAME}

clean:
		@${RM} ${OBJS}
		@make clean -C $(LIBFT_DIR)
		@echo ====== All *.o files were deleted =======

fclean:	clean
		@${RM} ${NAME}
		@make fclean -C $(LIBFT_DIR)
		@echo ====== libftprintf.a was deleted ========

re:	fclean all

.PHONY:	all clean fclean re