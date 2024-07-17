/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 22:53:27 by ahirotsu          #+#    #+#             */
/*   Updated: 2024/06/15 19:01:15 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	sp_error(char *argv)
{
	char	**str;

	str = ft_split(argv, ' ');
	error_mg(str[0]);
	free_sp(&str);
	return (1);
}

void	split_su(t_box *list, char **argv)
{
	list->comm1 = ft_split(argv[2], ' ');
	if (list->comm1 == NULL)
	{
		perror("malloc_error");
		exit (1);
	}
	list->comm2 = ft_split(argv[3], ' ');
	if (list->comm2 == NULL)
	{
		perror("malloc_error");
		exit (1);
	}
	list->a_path = list->comm1[0];
	list->b_path = list->comm2[0];
}

void	exit_error(char *str)
{
	sp_error(str);
	exit (1);
}

int	check_pa(t_box *list, char **argv, char **envp)
{
	int	a;
	int	b;

	split_su(list, argv);
	a = access(list->comm1[0], X_OK);
	b = access(list->comm2[0], X_OK);
	if (a == 0 && b == 0)
	{
		pipex(list, envp);
		exit (0);
	}
	if (a != 0 && b == 0)
		(exit_error(argv[2]));
	if (b != 0 && a == 0)
		(exit_error(argv[3]));
	if (a != 0 && b != 0)
	{
		(sp_error(argv[2]));
		(exit_error(argv[3]));
	}
	return (0);
}
