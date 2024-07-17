/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdch_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:42:52 by ahirotsu          #+#    #+#             */
/*   Updated: 2024/02/15 15:42:26 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	three_free(t_box *list)
{
	free_sp(&list->comm1);
	free_sp(&list->comm2);
	free_sp(&list->path);
}

int	a_access(t_box *list)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	while (list->path[i] != NULL)
	{
		list->a_path = ft_strjoin(list->path[i], list->comm1[0]);
		if (list->a_path == NULL)
			return (0);
		if (access(list->a_path, X_OK) == 0)
		{
			f = 1;
			break ;
		}
		free (list->a_path);
		i++;
	}
	if (f == 0)
	{
		three_free(list);
		return (0);
	}
	return (1);
}

int	b_access(t_box *list)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	while (list->path[i] != NULL)
	{
		list->b_path = ft_strjoin(list->path[i], list->comm2[0]);
		if (list->b_path == NULL)
			return (0);
		if (access(list->b_path, X_OK) == 0)
		{
			f = 1;
			break ;
		}
		free (list->b_path);
		i++;
	}
	if (f == 0)
	{
		three_free(list);
		free (list->a_path);
		return (0);
	}
	return (1);
}
