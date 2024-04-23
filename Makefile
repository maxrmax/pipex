# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/02 15:29:54 by mring             #+#    #+#              #
#    Updated: 2024/04/23 18:29:34 by mring            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = pipex
CC      = cc
SRCS    = pipex.c
HEADERS = pipex.h
CFLAGS  = -Wall -Wextra -Werror -I.
DFLAGS  = -L./ft_printf -lftprintf

# ft_printf library source files
FT_PRINTF_SRCS = ft_printf/ft_printf.c \
				ft_printf/ft_printf_print.c \
				# Add more source files if needed

FT_PRINTF_OBJS = $(FT_PRINTF_SRCS:.c=.o)

# Rule to compile ft_printf library source files
$(FT_PRINTF_OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# pipex object files
OBJECTS = ${SRCS:.c=.o}

# Rule to compile pipex source files
%.o: %.c $(HEADERS) Makefile
	$(CC) -c ${CFLAGS} -o $@ $<

${NAME}: ${OBJECTS} ${FT_PRINTF_OBJS}
	$(CC) ${CFLAGS} ${LDFLAGS} -o ${NAME} ${OBJECTS} ${FT_PRINTF_OBJS}

all: ${NAME}

clean:
	rm -f ${OBJECTS} ${FT_PRINTF_OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

# NAME	= pipex
# CC		= cc
# SRCS	= pipex.c
# HEADERS = pipex.h
# CFLAGS	= -Wall -Wextra -Werror -I. -v
# DFLAGS = -L./ft_printf -lftprintf

# OBJECTS	= ${SRCS:.c=.o}

# %.o: %.c $(HEADERS) Makefile
# 	$(CC) -c ${CFLAGS} -o $@ $<

# ${NAME}: ${OBJECTS}
# 	$(CC) ${CFLAGS} ${LDFLAGS} -o ${NAME} ${OBJECTS}

# all: ${NAME}

# clean:
# 	rm -f ${OBJECTS}

# fclean: clean
# 	rm -f ${NAME}

# re: fclean all

# .PHONY:		all clean fclean re
# # informs comp that these are not files