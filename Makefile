# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/02 15:29:54 by mring             #+#    #+#              #
#    Updated: 2024/05/07 16:22:00 by mring            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = pipex
SRCS    = pipex.c utils1.c utils2.c
# CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)

# Object files from ft_printf
FT_PRINTF_OBJS = ft_printf/ft_printf.o ft_printf/ft_printf_print.o

# Object files from libft
LIBFT_OBJ = ft_libft/ft_strlen.o ft_libft/ft_calloc.o ft_libft/ft_substr.o ft_libft/ft_strdup.o ft_libft/ft_strlcpy.o ft_libft/ft_memcpy.o ft_libft/ft_strncmp.o ft_libft/ft_strjoin.o ft_libft/ft_split.o

# Compilation rule for pipex
$(NAME): $(OBJS) $(FT_PRINTF_OBJS) $(LIBFT_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FT_PRINTF_OBJS) $(LIBFT_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: ${NAME}

clean:
	rm -f ${OBJS} $(FT_PRINTF_OBJS) $(LIBFT_OBJ)

fclean: clean
	rm -f ${NAME}

re: fclean all

# Run rule (make and then execute)
run: $(NAME)
	./$(NAME) infile "ls -l" "wc -l" outfile

# Run
doc: $(NAME)
	./$(NAME) here_doc LIM "ls -l" "wc" outfile

.PHONY:		all clean fclean re
# informs comp that these are not files