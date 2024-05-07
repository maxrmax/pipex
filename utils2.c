/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:11:39 by mring             #+#    #+#             */
/*   Updated: 2024/05/07 18:51:52 by mring            ###   ########.fr       */
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
