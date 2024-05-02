/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:30:03 by mring             #+#    #+#             */
/*   Updated: 2024/05/02 18:35:14 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	mexit(char *err, int perr)
{
	if (perr)
	{
		write(2, "Pipex: ", 7);
		perror(err);
	}
	else
		write(2, err, ft_strlen(err));
	exit(1);
}



int	main(int argc, char **argv, char **envp)
{
	int		infile;
	int		outfile;

	if (argc < 5)
		return (mexit("Invalid number of arguments\n", 1));
	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (infile < 0)
		mexit("Infile", 1);
	if (outfile < 0)
		mexit("Outfile", 1);
	dup2(infile, 0); // fd from 3 to 0
	dup2(outfile, 1); // fd from 4 to 1
}
