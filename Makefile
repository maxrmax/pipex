# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/02 15:29:54 by mring             #+#    #+#              #
#    Updated: 2024/04/27 13:22:08 by mring            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = pipex
SRCS    = pipex.c
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)

# Object files from ft_printf
FT_PRINTF_OBJS = ft_printf/ft_printf.o ft_printf/ft_printf_print.o

# Object files from libft
LIBFT_OBJ = ft_libft/.o

# Compilation rule for pipex
$(NAME): $(OBJS) $(FT_PRINTF_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FT_PRINTF_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: ${NAME}

clean:
	rm -f ${OBJS} $(FT_PRINTF_OBJS)

fclean: clean
	rm -f ${NAME}

re: fclean all

# Run rule (make and then execute)
run: $(NAME)
	./$(NAME) infile "ls -l" "wc -l" outfile

.PHONY:		all clean fclean re
# informs comp that these are not files