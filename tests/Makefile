# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 12:56:35 by prasingh          #+#    #+#              #
#    Updated: 2025/11/22 19:03:17 by prasingh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = bonus
SRC         = bonus.c
SRC_DIR     = ../libft/*.c
LIBFT_DIR   = ../libft
LIBFT       = $(LIBFT_DIR)/libft.a

CC          = cc
CFLAGS      = -lbsd
INCLUDE     = -I$(LIBFT_DIR)
LIBFLAGS    = -L$(LIBFT_DIR) -lft
RM          = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(SRC) $(SRC_DIR) 
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC) $(LIBFLAGS) -o $@

$(LIBFT): 
	cd $(LIBFT_DIR) && make -c && cd ..
	
clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re force
