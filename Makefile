# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mathis <mathis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 17:21:55 by mathis            #+#    #+#              #
#    Updated: 2022/06/15 16:50:54 by mathis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME1 = server
NAME2 = client

SRC = mt_utils.c

all : $(NAME1) $(NAME2)

$(NAME1) : $(NAME1:%=%.o) $(SRC:%.c=%.o)
	$(CC) $(CFLAGS) $^ -o $@

$(NAME2) : $(NAME2:%=%.o) $(SRC:%.c=%.o)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f *.o

fclean : clean
	rm -f server client

re : fclean all

.PHONY : all clean fclean re