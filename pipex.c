/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:30:03 by mring             #+#    #+#             */
/*   Updated: 2024/05/10 16:15:31 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	mexit(char *cmd, int errcode)
{
	char	*errmsg;

	if (errcode == 2 && cmd == NULL)
		exit(2);
	if (errcode == 1 || errcode == 0)
		errmsg = ": No such file or directory\n";
	else if (errcode == 2)
		errmsg = ": command not found\n";
	else if (errcode == 127)
		errmsg = ": command not found\n";
	else
		exit(errcode);
	write(STDERR_FILENO, "pipex: ", 7);
	write(STDERR_FILENO, cmd, ft_strlen(cmd));
	write(STDERR_FILENO, errmsg, ft_strlen(errmsg));
	exit(errcode);
}

void	exec(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = p_split(cmd);
	if (ft_strchr_i(args[0], '/') > -1)
		path = args[0];
	else
		path = get_path(args[0], envp);
	execve(path, args, envp);
	mexit(cmd, 127);
}

void	piping(char *cmd1, char *cmd2, char **envp, int infile)
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipefd[2];
	int		status;

	if (pipe(pipefd) == -1)
		mexit("Pipe", 3);
	pid1 = fork();
	if (pid1 == -1)
		mexit(cmd2, 2);
	if (pid1 == 0)
		child1(pipefd, cmd1, envp, infile);
	pid2 = fork();
	if (pid2 == -1)
		mexit(cmd1, 2);
	if (pid2 == 0)
		child2(pipefd, cmd2, envp);
	if (!close(pipefd[0]) && !close(pipefd[1]) && infile > 0)
		waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 127)
		exit(127);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 2)
		mexit(NULL, 2);
}

int	main(int argc, char **argv, char **envp)
{
	int		infile;
	int		outfile;

	if (argc < 5)
		mexit("Invalid number of arguments\n", 3);
	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (outfile < 0)
		mexit("output", 0);
	dup2(infile, 0);
	dup2(outfile, 1);
	piping(argv[2], argv[3], envp, infile);
	if (infile < 0)
		mexit("input", 0);
}
