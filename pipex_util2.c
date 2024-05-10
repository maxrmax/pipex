/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:11:39 by mring             #+#    #+#             */
/*   Updated: 2024/05/10 16:26:03 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(int *pipefd, char *cmd1, char **envp, int infile)
{
	if (infile > 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], 1);
	}
	close(pipefd[1]);
	exec(cmd1, envp);
}

void	child2(int *pipefd, char *cmd2, char **envp)
{
	close(pipefd[1]);
	dup2(pipefd[0], 0);
	close(pipefd[0]);
	exec(cmd2, envp);
}

char	**p_trim_args(char *cmd)
{
	char	**cmd_args;
	char	*q_args;
	int		i;
	int		q_flag;

	q_args = p_trim_check(cmd);
	cmd_args = ft_split(cmd, ' ');
	if (ft_strchr_i(cmd, '\"') >= 0 && ft_strchr_i(cmd, '\'') >= 0)
		q_args = ft_substr(q_args, 0, ft_strlen(q_args));
	i = 0;
	while (cmd_args[0] && cmd_args[i] != NULL)
	{
		if ((ft_strchr_i(cmd_args[i], '\'') >= 0
				|| ft_strchr_i(cmd_args[i], '\"') >= 0) && q_flag != 1)
		{
			cmd_args[i] = q_args;
			q_flag = 1;
		}
		else if (i > 0 && q_flag == 1)
			cmd_args[i] = NULL;
		i++;
	}
	return (cmd_args);
}

char	**p_split(char *cmd)
{
	char	**cmd_args;

	if (ft_strchr(cmd, '\'') || ft_strchr(cmd, '\"'))
		cmd_args = p_trim_args(cmd);
	else
		cmd_args = ft_split(cmd, ' ');
	if (!cmd)
		mexit("Failed to split arguments", 1);
	return (cmd_args);
}

char	*p_trim_check(char *cmd)
{
	char	*q_args;

	if (ft_strchr(cmd, '\'') && (ft_strchr(cmd, '\'')
			< ft_strchr(cmd, '\"') || !ft_strchr(cmd, '\"')))
		q_args = ft_substr(cmd, ft_strchr_i(cmd, '\'') + 1,
				ft_strlen(cmd) - ft_strchr_i(cmd, '\'') - 2);
	else
		q_args = ft_substr(cmd, ft_strchr_i(cmd, '\"') + 1,
				ft_strlen(cmd) - ft_strchr_i(cmd, '\"') - 2);
	return (q_args);
}
