NAME = push_swap

SRCS = pushswap.c swap.c sw_utils.c sort_utils.c countsorts.c \
		args_utils.c args.c simple_sorts.c sorts.c inssort.c inssort_utils.c 

LIB = ./libft/libft.a

OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

HEADER = include/pushswap.h

CC = gcc
FLAGS = -g -Wall -Wextra -Werror
RM =  rm -rf

LIB_DIR = ./libft
SRCS_DIR = ./srcs
OBJS_DIR = ./objs
INC_DIR = ./include

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(FLAGS) $(OBJS) $(LIB) -o $(NAME)	

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER)
	$(MAKE)	-C $(LIB_DIR)
	mkdir -p $(OBJS_DIR)
	$(CC) $(FLAGS) -I $(LIB_DIR) -c $< -o $@

.c.o:
	$(CC) $(FLAGS) -I $(INC_DIR) -c $< -o $(<:.c=.o)

clean:
	$(MAKE) clean -C $(LIB_DIR)
	@rm -rfv $(OBJS_DIR)
 
fclean: clean
	$(MAKE) fclean -C $(LIB_DIR)
	@rm -rf $(NAME)

re: fclean all clean

.PHONY: all clean fclean re
