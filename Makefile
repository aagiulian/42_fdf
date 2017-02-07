# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agiulian <arthur.giuliano@student.42.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/17 22:23:16 by agiulian          #+#    #+#              #
#    Updated: 2017/02/07 17:45:49 by agiulian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = fdf

SRC = main.c

HEAD = -Ilibft/includes/ -I. -I /usr/X11/include -L /usr/X11/lib -l mlx -I framework OpenGL -framework AppKit

ECHO = printf

OBJECT = $(SRC:.c=.o)

CFLAGS = $(HEAD) -l mlx -framework OpenGL -framework AppKit -O3 -g

%.o	:	%.c 
		@$(CC) $(CFLAGS) -o $@ -c $<&& $(ECHO) "\033[31m["$@"] \n\033[0m"

all: $(NAME)

$(NAME): $(OBJECT)
	gcc -o $(NAME) $(OBJECT)

clean:
	@rm -f $(OBJECT) && $(ECHO) "\033[32m[Deleting objects]\033[0m\n"

fclean: clean
	rm -f $(NAME)

re: fclean all
