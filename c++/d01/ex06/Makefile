# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 19:50:52 by cbilbo            #+#    #+#              #
#    Updated: 2021/12/08 16:24:54 by cbilbo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Karen-filter

SRCS = main.cpp Karen.cpp
OBJS = $(patsubst %.cpp,%.o,$(SRCS))

CXX = c++
CXXFLAGS = -g -Wall -Werror -Wextra -std=c++98
RM = rm -rf
HEADER = Karen.hpp

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