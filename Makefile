# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/02 15:29:54 by mring             #+#    #+#              #
#    Updated: 2024/04/03 10:49:02 by mring            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#definitions
NAME	= pipex
CC		= gcc
SRCS	= pipex.c
HEADERS = pipex.h
CFLAGS	= -Wall -Wextra -Werror

OBJECTS	= ${SRCS:.c=.o}

%.o: %.c $(HEADERS) Makefile
	$(CC) -c ${CFLAGS} -o $@ $<

${NAME}: ${OBJECTS}
	ar rc ${NAME} ${OBJECTS}
	ranlib ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY:		all clean fclean re
