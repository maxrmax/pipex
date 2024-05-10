# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/02 15:29:54 by mring             #+#    #+#              #
#    Updated: 2024/05/10 16:30:35 by mring            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := pipex
SRCS    := pipex.c pipex_util.c pipex_util2.c
CFLAGS := -Wall -Wextra -Werror
CC := @cc

LIBS := ft_libft/libft.a

OBJS := $(SRCS:.c=.o)

$(NAME): $(OBJS) $(LIBS)
	@echo building pipex...
	$(CC) $(CFLAGS) -o $@ $^

$(LIBS):
	@make -C ft_libft

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -g

all: ${NAME}

clean:
	@echo cleaning pipex...
	@rm -f ${OBJS}
	@make clean -C ft_libft

fclean: clean
	@echo fcleaning pipex...
	@rm -f ${NAME} ${OBJS}
	@make fclean -C ft_libft

re: fclean all

.PHONY:		all clean fclean re run awk
# informs comp that these are not files