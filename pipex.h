/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:30:05 by mring             #+#    #+#             */
/*   Updated: 2024/05/10 16:25:56 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include "./ft_libft/libft.h"

int		mexit(char *cmd, int errcode);
int		ft_strchr_i(const char *s, int c);
char	*join_path(char *path, char *bin);
char	*get_path(char *cmd, char **envp);
char	*ft_strndup(char *str, unsigned int n);
void	exec(char *cmd, char **envp);
void	piping(char *cmd1, char *cmd2, char **envp, int infile);
void	child1(int pipefd[2], char *cmd, char **envp, int infile);
void	child2(int pipefd[2], char *cmd, char **envp);
char	**p_trim_args(char *cmd);
char	*p_trim_check(char *cmd);
char	**p_split(char *cmd);
int		main(int argc, char **argv, char **envp);

#endif