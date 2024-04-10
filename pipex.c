/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:30:03 by mring             #+#    #+#             */
/*   Updated: 2024/04/10 17:49:51 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/*
allowed functions:
	open, close, read, write,
	malloc, free, perror,
	strerror, access, dup, dup2,
	execve, exit, fork, pipe,
	unlink, wait, waitpid

	ft_printf and any equivalent
	YOU coded
*/

// ./pipex file1 cmd1 cmd2 file2
// <file cmd1 | cmd2 > file2

//bonus:
// ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
// should behave like
// < file1 cmd1 | cmd2 | ... | cmdn > file2
char	pipex(void)
{
	return (0);
}

	// 0. Check arguments
	// 1. Parse arguments
	// 2. Open files
	// 3. Create pipes
	// 4. Fork processes
	// 5. Execute commands
	// 6. Close pipes
	// 7. Close files
	// 8. Wait for children
	// 9. Return status

//init_pipex
//check_args
//parse_cmds
//parse_args
//while cmds
// exec
	// pipe, fork, if child/dup2/execv,else/close
//cleanup
int	main(int argc, char *argv[])
{
	pid_t	pid;
	int		i;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		printf("child (pid: %d)\n", getpid());
	else
		printf("parent (pid: %d)\n", getpid());
	i = 0;
	while (i < argc)
	{
		printf("Argument %d: %s\n", i, argv[i]);
		i++;
	}
	return (0);
}

// exploit, programmatic expression of will