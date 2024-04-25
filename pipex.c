/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:30:03 by mring             #+#    #+#             */
/*   Updated: 2024/04/25 15:50:53 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>

int	pipex()
{
	return (0);
}

int	main(int argc, char *argv[])
{
	int		fd;
	int i;

	// TODO : n argc for bonus
	if (argc <= 4)
		ft_printf("not enough arguments\n");
	// access fail = -1
	// when input file is not found
	if (access(argv[1], R_OK) == -1)
		ft_printf("file <%s> not found\n", argv[1]);
	// when output file is not found, create it
	if (access(argv[argc - 1], F_OK) == -1 )
		fd = open(argv[argc - 1], O_CREAT, 00644);
	// if output file is not accessable
	if (access(argv[argc - 1], W_OK) == -1)
		ft_printf("%s: writing not permitted", argv[argc - 1]);
	// iterate over every argument
	i = 0;
	while (i < argc)
	{
		ft_printf("%d: %s\n", i, argv[i]);
		i++;
	}
	//
	//
	if (fd == -1)
		ft_printf("failed to open <%s> - check permissions\n", argv[1]);
	ft_printf("%s - %d - %s\n", argv[0], argc, argv[argc - 1]);
	//
	
	//
	//
	//
	//
	close(fd);
	return (0);
}

	// TODO - need last n argument for argv, figure this out
/*
< file1 cmd1 | cmd2 > file2
bash: file1: No such file or directory
bash: cmd2: command not found

< infile cmd1 | cmd2 > file2
bash: cmd1: command not found
bash: cmd2: command not found

< infile ls -l | cmd2 > file2
bash: cmd2: command not found

< infile ls -l | wc -l > file2
644 perm for created file
# creates file2

Always created file2 if it was missing
All the cases are displayed here.
*/

/*
BONUS:

ls -l << LIM | wc -l >> file
> one
> two
> three
> four
>>>>> file created and 11 with new line

<< EOF cat | head -n 5 | wc -l >> out
(1) test
(2) this
(3) nuts
(4) motherf
EOF
>>>> 4\n



*/