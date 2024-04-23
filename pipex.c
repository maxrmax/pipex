/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:30:03 by mring             #+#    #+#             */
/*   Updated: 2024/04/23 18:31:40 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	int		fd;

	ft_printf("test\n");
	if (argc < 5)
		return (write(1, "0", 1), 0);
	if (access("infile", R_OK) == -1)
		ft_printf("no such file or directory: %s", argv[1]);
	fd = open("infile", O_CREAT | O_RDONLY, 0644);
	close(fd);
	return (0);
}
