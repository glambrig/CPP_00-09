# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glambrig <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/17 10:34:27 by glambrig          #+#    #+#              #
#    Updated: 2024/04/12 13:02:15 by glambrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean NAME

CFLAGS = -lstdc++ -Wall -Wextra -Werror -g

NAME = brain

SRC = *.cpp

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	g++ $(SRC) -o $(NAME) $(CFLAGS)

clean:
	rm -rf $(NAME)

re: clean all
