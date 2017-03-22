# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agiulian <arthur.giuliano@student.42.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/17 22:23:16 by agiulian          #+#    #+#              #
#    Updated: 2017/03/22 16:49:56 by agiulian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = fdf

SRC = main.c \
	  parse.c \
	  commands.c

HEAD = -Ilibft/includes/ -Iprintf/. -I. -I/usr/local/include

LIB = -Llibft -lftprintf -L/usr/local/lib/

ECHO = printf

OBJ = $(SRC:.c=.o)

LIBUNIT = -lmlx -framework OpenGL -framework AppKit

CFLAGS = $(HEAD) -Wall -Werror -Wextra

%.o	:	%.c
		@$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(CFLAGS) -o $(NAME) $(LIB) $(OBJ) $(LIBUNIT)
	@$(ECHO) "\033[32m[Compiling fdf Project]\033[0m\n"

clean:
	@make clean -C libft
	@rm -f $(OBJ) && $(ECHO) "\033[32m[Deleting fdf objects]\033[0m\n"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@$(ECHO) "\033[32m[Deleting fdf Binary]\033[0m\n"

re: fclean all
