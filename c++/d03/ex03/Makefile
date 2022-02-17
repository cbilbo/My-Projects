# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 17:59:13 by cbilbo            #+#    #+#              #
#    Updated: 2021/12/13 15:56:34 by cbilbo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = DiamondTrap

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJS = $(patsubst %.cpp,%.o,$(SRCS))
D_FILES = $(patsubst %.cpp,%.d,$(SRCS))

CXX = c++
CXXFLAGS = -g -Wall -Werror -Wextra -std=c++98
OPT_FLAGS = -O2
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OPT_FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(OPT_FLAGS) -c $< -o $@ -MD

include $(wildcard $(D_FILES))

clean:
	$(RM) $(OBJS) $(D_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re