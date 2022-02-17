NAME = Moar_brainz!

SRCS = Zombie.cpp main.cpp ZombieHorde.cpp
OBJS = $(patsubst %.cpp,%.o,$(SRCS))
HEADER = Zombie.hpp

CXX = c++
CXXFLAGS = -g -Wall -Werror -Wextra -std=c++98
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re