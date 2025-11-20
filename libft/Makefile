# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/19 15:52:06 by prasingh          #+#    #+#              #
#    Updated: 2025/11/20 13:17:15 by prasingh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libft.a

SRC_PART1   = ft_isalpha.c 

SRC_PART2   = 

SRC         = $(SRC_PART1) $(SRC_PART2)

SRC_BONUS   = 

OBJ         = $(SRC:.c=.o)
OBJ_BONUS   = $(SRC_BONUS:.c=.o)

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar
ARFLAGS     = rcs
RM          = rm -f
INCLUDE     = -I.

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

bonus: $(OBJ) $(OBJ_BONUS)
	$(AR) $(ARFLAGS) $(NAME) $^

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
