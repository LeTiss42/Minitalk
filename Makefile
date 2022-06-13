# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mathis <mathis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 17:21:55 by mathis            #+#    #+#              #
#    Updated: 2022/06/13 18:13:18 by mathis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all : server client

server : server.o
	gcc -Wall -Wextra -Werror -o server server.o

server.o : server.c
	gcc -Wall -Wextra -Werror -o server.o -c server.c

client : client.o
	gcc -Wall -Wextra -Werror -o client client.o

client.o : client.c
	gcc -Wall -Wextra -Werror -o client.o -c client.c

clean :
	rm -f *.o

fclean : clean
	rm -f server client

re : fclean all

.PHONY : all clean fclean re