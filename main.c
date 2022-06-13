/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:31:21 by ceatgie           #+#    #+#             */
/*   Updated: 2022/06/12 11:43:02 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_one(int	*pipefd, int *fd, char *argv[], char *envp[])
{
	char 	**cmd;
	pid_t	c_pid;

	c_pid = fork();
	if (c_pid < 0)
		ft_finish("fork");
	if (c_pid == 0)
	{
		fd[0] = open(argv[1], O_RDONLY);
		if (fd[0] < 0)
			ft_finish(argv[1]);
		cmd = ft_split(argv[2], ' ');
		close(pipefd[0]);
		dup2(fd[0], STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		if (cmd[0] && ft_path(cmd[0], envp))
		{
			execve(ft_path(cmd[0], envp), cmd, envp);
			ft_free_double_array(cmd);
		}
		else
			cmd_not_found(cmd);
	}
}

void	child_two(int *pipefd, int *fd, char *argv[], char *envp[])
{
	char	**cmd;
	pid_t	c_pid;
	
	c_pid = fork();
	if (c_pid < 0)
		ft_finish("fork");
	if (c_pid == 0)
	{
		fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd[1] < 0)
			ft_finish(argv[4]);
		cmd = ft_split(argv[3], ' ');
		close(pipefd[1]);
		dup2(fd[1], STDOUT_FILENO);
		dup2(pipefd[0], STDIN_FILENO);
		if (cmd[0] && ft_path(cmd[0], envp))
		{
			execve(ft_path(cmd[0], envp), cmd, envp);
			ft_free_double_array(cmd);
		}
		else
			cmd_not_found(cmd);
	}
}

int main(int argc, char *argv[], char *envp[])
{
	int pipefd[2];
	int	fd[2];
	int	status;
	
	errno = 0;
	if (argc != 5)
		ft_how_to_use();
	if (pipe(pipefd) < 0)
		ft_finish(NULL);
	child_one(pipefd, fd, argv, envp);
	child_two(pipefd, fd, argv, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(-1, &status, 0);
	waitpid(-1,	&status, 0);
	return 0;
}