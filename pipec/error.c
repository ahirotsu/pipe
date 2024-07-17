/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 20:43:09 by ahirotsu          #+#    #+#             */
/*   Updated: 2024/02/15 18:02:47 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ew_mg(char *str)
{
	write(2, str, ft_strlen(str));
	return (0);
}

int	error_mg(char *str)
{
	perror(str);
	return (0);
}

void	list_free(t_box *list)
{
	free_sp(&list->comm1);
	free_sp(&list->comm2);
	free_sp(&list->path);
	free(list->a_path);
	free(list->b_path);
}

int	free_perror(char *str, t_box *list)
{
	list_free(list);
	perror(str);
	return (0);
}
