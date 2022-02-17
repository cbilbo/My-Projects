NAME = My_Awesome_Phonebook

SRCS = main.cpp contact.cpp phonebook.cpp
OBJS = $(patsubst %.cpp,%.o,$(SRCS))
D_FILES = $(patsubst %.cpp,%.d,$(SRCS))

CC = c++
FLAGS = -g -Wall -Werror -Wextra -std=c++98
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@ -MD

include $(wildcard $(D_FILES))
clean:
	$(RM) $(OBJS) $(D_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re