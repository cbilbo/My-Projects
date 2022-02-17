# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 19:50:52 by cbilbo            #+#    #+#              #
#    Updated: 2021/12/09 20:19:46 by cbilbo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = violence

SRCS = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJS = $(patsubst %.cpp,%.o,$(SRCS))
D_FILES = $(patsubst %.cpp,%.d,$(SRCS))

CXX = c++
CXXFLAGS = -g -Wall -Werror -Wextra -std=c++98
RM = rm -rf
HEADER = Weapon.hpp HumanA.hpp HumanA.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -MD

include $(wildcard $(D_FILES))

clean:
	$(RM) $(OBJS) $(D_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re