# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glambrig <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/17 10:34:27 by glambrig          #+#    #+#              #
#    Updated: 2024/04/15 12:57:37 by glambrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean NAME

CFLAGS = -lstdc++ -Wall -Wextra -Werror -g

NAME = violence

SRC = *.cpp

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	g++ $(SRC) -o $(NAME) $(CFLAGS)

clean:
	rm -rf $(NAME)

re: clean all
