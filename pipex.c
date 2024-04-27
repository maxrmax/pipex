/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:30:03 by mring             #+#    #+#             */
/*   Updated: 2024/04/27 13:29:12 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	pipex(int f1, int f2, char **argv)
// {

// }

int	main(int argc, char **argv)
{
	int	infile;
	int	outfile;

	if (argc != 5)
		ft_printf("input error\n");
	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (infile < 0 || outfile < 0)
		return (-1);
	ft_printf("o:%d\n", outfile);
	ft_printf("i:%d\n", infile);
	dup2(infile, 0); // change fd from infile to 0
	ft_printf("2:%d\n", infile);
	dup2(outfile, 1);
	ft_printf("3:%d\n", outfile);
	//
	pid_t pid;
	pid = fork();
	ft_printf("Post-Fork PID:%d\n", pid);
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}
	if (pid == 0)
	{
		ft_printf("Child PID:%d\n", getpid());
		exit (0);
	}
	else
	{
		int status;
		wait(&status);
		ft_printf("Parent PID %d, Child PID:%d\n", getpid(), pid);
		ft_printf("Status %d\n", status);
	}
	//
	//execve NULL
	//
	//
	//
	//
	//
	close(infile);
	close(outfile);
	return (0);
}

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