/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:30:03 by mring             #+#    #+#             */
/*   Updated: 2024/05/06 21:34:59 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	mexit(char *cmd, int errcode)
{
	char	*errmsg;

	if (errcode == 0)
		return (-1);
	if (errcode == 1)
		errmsg = ": No such file or directory\n";
	else if (errcode == 2 || errcode == 127)
		errmsg = ": command not found\n";
	else
		errmsg = ": Error occurred\n";
	write(2, "pipex: ", 7);
	write(2, cmd, ft_strlen(cmd));
	write(2, errmsg, ft_strlen(errmsg));
	exit(errcode);
}

int	ft_strchr_index(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return (i);
		i++;
	}
	if (s[i] == (char) c)
		return (i);
	return (-1);
}

char	*join_path(char *path, char *bin)
{
	char	*joined;
	int		i;
	int		j;

	joined = malloc(sizeof(char) * (ft_strchr_index(path, 0) + ft_strchr_index(bin, 0) + 2));
	i = 0;
	j = 0;
	while (path[j])
		joined[i++] = path[j++];
	joined[i++] = '/';
	j = 0;
	while (bin[j])
		joined[i++] = bin[j++];
	joined[i] = 0;
	return (joined);
}

int	str_ncmp(char *str1, char *str2, int n)
{
	while (--n > 0 && *str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	if (*str2 == '\0' && (*str1 == '\n' && !*(str2++)))
		return (0);
	return (*str2 - *str1);
}

char	*str_ndup(char *str, unsigned int n)
{
	char				*s;
	unsigned int		i;

	i = 0;
	s = malloc(sizeof(char) * (n + 1));
	while (i < n)
		s[i++] = *str++;
	s[n] = 0;
	return (s);
}

char	*get_path(char *cmd, char **envp)
{
	char	*path;
	char	*dir;
	char	*bin;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (str_ncmp(envp[i], "PATH=", 5) == 0)
		{
			path = envp[i] + 5;
			break ;
		}
		i++;
	}
	if (!path || !path[0])
		return (cmd);
	while (path && ft_strchr_index(path, ':') > -1)
	{
		dir = str_ndup(path, ft_strchr_index(path, ':'));
		bin = join_path(dir, cmd);
		free(dir);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += ft_strchr_index(path, ':') + 1;
	}
	return (cmd);
}

void	exec(char *cmd, char **envp)
{
	char	**args;
	char	*path;
	// int		i = 0;

	// TODO parse single '
	args = ft_split(cmd, ' ');
	// while (args[i])
	// {
	// 	ft_printf("\n:%s\n", args[i]);
	// 	i++;
	// }
	if (ft_strchr_index(args[0], '/') > -1)
		path = args[0];
	else
		path = get_path(args[0], envp);
	execve(path, args, envp);
	mexit(cmd, 127);
}

// TODO x child for x args / parallel running / concurrency
void	piping(char *cmd1, char *cmd2, char **envp, int infile)
{
	pid_t	pid1, pid2;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		mexit("Pipe", 3);
	pid1 = fork();
	if (pid1 == -1)
		mexit(cmd1, 2);
	if (pid1 == 0)
	{
		if (infile > 0)
		{
			close(pipefd[0]); // if infile 0, disable
			dup2(pipefd[1], 1); // if infile 0, disable
		}
		close(pipefd[1]);
		exec(cmd1, envp);
	}
	pid2 = fork();
	if (pid2 == -1)
		mexit(cmd2, 2);
	if (pid2 == 0)
	{
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		close(pipefd[0]); // if infile 0, disable
		exec(cmd2, envp);
	}
	close(pipefd[0]); // if infile 0, disable
	close(pipefd[1]);
	if (infile > 0)
		waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int		infile;
	int		outfile;

	if (argc < 5)
		return (mexit("Invalid number of arguments\n", 3));
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		mexit("input", 0);
	outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (outfile < 0)
		mexit("output", 0);
	dup2(infile, 0);
	dup2(outfile, 1);
	piping(argv[2], argv[3], envp, infile);
	ft_printf("next stuck1\n");
	return (0);
}
