/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:46:08 by ahirotsu          #+#    #+#             */
/*   Updated: 2024/02/15 17:44:19 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_arg1(t_box *list)
{
	if (list->comm1[0][0] != '/' && list->comm1[0][0] != '.')
		return (0);
	if (access(list->comm1[0], X_OK) != 0)
	{
		three_free(list);
		perror("access_error");
		exit(1);
	}
	list->a_path = ft_strjoin(list->comm1[0], "");
	if (list->a_path == NULL)
	{
		three_free(list);
		perror("malloc_error");
		exit(1);
	}
	return (1);
}

int	check_arg2(t_box *list)
{
	if (list->comm2[0][0] != '/' && list->comm2[0][0] != '.')
		return (0);
	if (access(list->comm2[0], X_OK) != 0)
	{
		three_free(list);
		free(list->a_path);
		perror("access_error");
		exit(1);
	}
	list->b_path = ft_strjoin(list->comm2[0], "");
	if (list->b_path == NULL)
	{
		three_free(list);
		free(list->a_path);
		perror("malloc_error");
		exit(1);
	}
	return (1);
}
