NAME = bank

SRCS = Account.cpp tests.cpp
OBJS = $(patsubst %.cpp,%.o,$(SRCS))
HEADER = Account.hpp

CC = c++
FLAGS = -g -Wall -Werror -Wextra -std=c++98
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re