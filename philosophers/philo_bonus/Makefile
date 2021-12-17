NAME = philo_bonus

SRCS = phil.c parser.c utils1.c processes.c check_errors.c
OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

HEADER = include/phil.h

CC = gcc
FLAGS = -g -Wall -Wextra -Werror -pthread
RM = rm -rf

SRC_DIR = ./srcs
OBJ_DIR = ./objs
INC_DIR = ./include

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -I $(INC_DIR) -c $< -o $@

.c.o:
	$(CC) $(FLAGS) -I $(INC_DIR) -c $< -o $(<:.c=.o)

clean:
	rm -rfv $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
