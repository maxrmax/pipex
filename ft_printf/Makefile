# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/06 12:40:14 by mring             #+#    #+#              #
#    Updated: 2024/02/07 16:49:44 by mring            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= ft_printf.c ft_printf_print.c

HEADERS = ft_printf.h

OBJECTS	= ${SRCS:.c=.o}

CFLAGS	= -Wall -Wextra -Werror

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
