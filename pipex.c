/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:30:03 by mring             #+#    #+#             */
/*   Updated: 2024/05/02 18:31:59 by mring            ###   ########.fr       */
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
	while (envp[i] && str_ncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (cmd);
	path = envp[i] + 5;
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

	args = ft_split(cmd, ' ');
	if (ft_strchr_index(args[0], '/') > -1)
		path = args[0];
	else
		path = get_path(args[0], envp);
	execve(path, args, envp);
	mexit("execve", 1);
}

void	piping(char *cmd, char **envp, int infile)
{
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		mexit("Pipe", 1);
	pid = fork();
	if (pid)
	{
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		if (infile == 0)
			exit(1);
		else
			exec(cmd, envp);
	}
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
	piping(argv[2], envp, infile);
	exec(argv[3], envp);
}
