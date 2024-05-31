# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glambrig <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/17 10:34:27 by glambrig          #+#    #+#              #
#    Updated: 2024/05/31 14:30:35 by glambrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean NAME

CFLAGS = -lstdc++ -Wall -Wextra -Werror -std=c++98 -g

NAME = a.out

SRC = *.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)

$(OBJ):
	c++ $(SRC) -o $(NAME) $(CFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	
re: clean all
