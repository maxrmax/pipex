/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:51:38 by mring             #+#    #+#             */
/*   Updated: 2024/04/08 05:36:08 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buf[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	char		*next_line;
	int			amountread;
	int			to_copy;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup(buf[fd]);
	if (!line)
		return (free(line), NULL);
	amountread = 1;
	while (!(ft_strchr(line, '\n')) && amountread > 0)
	{
		amountread = read(fd, buf[fd], BUFFER_SIZE);
		if (amountread < 0)
			return (free(line), buf[fd][0] = '\0', NULL);
		line = ft_strjoin(line, buf[fd], amountread);
		if (ft_strlen(line) == 0)
			return (free(line), NULL);
	}
	next_line = ft_strchr(line, '\n');
	to_copy = err_check(next_line, line, buf[fd]);
	return (line[to_copy] = '\0', line);
}

int	err_check(char *next_line, char *line, char *buf)
{
	int	to_copy;

	if (next_line != NULL)
	{
		to_copy = next_line - line + 1;
		ft_strlcpy(buf, next_line + 1, BUFFER_SIZE + 1);
	}
	else
	{
		to_copy = ft_strlen(line);
		buf[0] = '\0';
	}
	return (to_copy);
}
