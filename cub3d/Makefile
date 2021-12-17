# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/09 15:04:55 by cbilbo            #+#    #+#              #
#    Updated: 2021/04/27 19:27:53 by cbilbo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC = ft_errs.c \
		ft_cub.c \
		ft_utils.c \
		ft_pars.c \
		ft_args.c \
		ft_fill_map.c \
		ft_draw.c \
		ft_move.c \
		ft_rays.c \
		ft_txrs.c \
		ft_spr.c \
		ft_bmp.c \

LIB = libft.a
LIB_DIR = libs/libft
MLX_DIR = libs/minilibx_opengl
MLX = libmlx.a
MLXLIN_DIR = libs/minilibx_linux
MLXLIN = libmlx.a 
CC = clang

CFLAGS = -g -Wall -Wextra -Werror
LIN_MOVE = -D FORWARD=119 -D BACK=115 -D LEFT=97 -D RIGHT=100 -D ROTLEFT=75 -D ROTRIGHT=77 -D ESC=27

SRC_DIR = ./srcs
OBJ_DIR = ./srcs/objs
INC_DIR = include

HEADER = include/ft_cub.h

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
DPD = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.d))

all:
	@	$(MAKE) -j4 -C $(LIB_DIR)
	@	$(MAKE) -j4 -C $(MLX_DIR)
	@	cp $(MLX_DIR)/$(MLX) ../cub
	@	$(MAKE) -j4 $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@	$(CC) $(CFLAGS) $(OBJ) $(LIB_DIR)/$(LIB) $(MLX_DIR)/$(MLX) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
		
linux:
	@$(MAKE) -C $(LIB_DIR)
	@$(MAKE) -C $(MLXLIN_DIR)
	@$(MAKE) -j4 pinguin

pinguin: $(OBJ)
	@$(CC) $(CFLAGS) $(LIN_MOVE) -o $(NAME) $(OBJ) $(LIB_DIR)/$(LIB) -L $(MLXLIN_DIR) -lmlx -lm -lX11 -lXext

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(LIB_DIR) -I $(MLXLIN_DIR) -c $< -o $@

.c.o:
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $(<:.c=.o)

clean:
	@rm -rf $(OBJ_DIR)

fclean:	clean
	@rm -rf $(NAME) $(MLX)
	@$(MAKE) clean -C $(MLX_DIR)
	@$(MAKE) fclean -C $(LIB_DIR)

re: fclean all

rere: re
	@$(MAKE) re -j4 -C $(LIB_DIR)

relinux: fclean linux
	@$(MAKE) -j4 re -C $(LIB_DIR)

.PHONY: all, clean, fclean, re, pinguin, linux, relinux, rere

-include $(DPD)