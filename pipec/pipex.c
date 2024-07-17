/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:06:47 by ahirotsu          #+#    #+#             */
/*   Updated: 2024/06/15 19:03:21 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	rd_process(t_box *list, char **envp)
{
	if (dup2(list->outfile, 1) < 0)
	{
		free_perror("dup2_error", list);
		exit(1);
	}
	close(list->outfile);
	if (dup2(list->fd[R], 0) < 0)
	{
		free_perror("dup2_error", list);
		exit(1);
	}
	close(list->fd[W]);
	close(list->fd[R]);
	if (execve(list->b_path, list->comm2, envp) == -1)
	{
		free_perror("execve_error", list);
		exit(1);
	}
}

void	nd_process(t_box *list, char **envp)
{
	pid_t	pid2;

	pid2 = fork();
	if (pid2 == -1)
	{
		free_perror("fork_error", list);
		exit(1);
	}
	if (pid2 == 0)
		rd_process(list, envp);
	else
	{
		close(list->fd[W]);
		if (dup2(list->fd[R], 0) < 0)
		{
			free_perror("dup2_error", list);
			exit(1);
		}
		close(list->fd[R]);
	}
}

void	st_process(t_box *list, char **envp)
{
	if (dup2(list->infile, 0) < 0)
	{
		free_perror("dup2_error", list);
		exit(1);
	}
	close(list->infile);
	if (dup2(list->fd[W], 1) < 0)
	{
		free_perror("dup2_error", list);
		exit(1);
	}
	close(list->fd[W]);
	close(list->fd[R]);
	if (execve(list->a_path, list->comm1, envp) == -1)
	{
		free_perror("execve_error", list);
		exit(1);
	}
}

int	pipex(t_box *list, char **envp)
{
	pid_t	pid;
	int		status;

	if (pipe(list->fd) == -1)
		return (free_perror("pipe_error", list));
	pid = fork();
	if (pid == -1)
		return (free_perror("fork_error", list));
	else if (pid == 0)
		st_process(list, envp);
	else
	{
		nd_process(list, envp);
		if (waitpid(pid, &status, 0) == -1)
		{
			free_perror("waitpid_error", list);
			exit(1);
		}
	}
	return (1);
}
