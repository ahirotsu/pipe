/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 21:17:52 by ahirotsu          #+#    #+#             */
/*   Updated: 2024/06/21 21:07:12 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*copy_envp(char *envp)
{
	char	*tmp;
	int		i;
	int		s;

	s = 0;
	i = ft_strlen(envp);
	tmp = malloc(sizeof(char) * i - 4);
	if (tmp == NULL)
		return (NULL);
	while (envp[s + 5] != '\0')
	{
		tmp[s] = envp[s + 5];
		s++;
	}
	tmp[s] = '\0';
	return (tmp);
}

int	sp_main(char **argv, char *tmp, t_box *list)
{
	list->comm1 = ft_split(argv[2], ' ');
	if (list->comm1 == NULL)
		return (error_mg("malloc_error"));
	list->comm2 = ft_split(argv[3], ' ');
	if (list->comm2 == NULL)
	{
		free_sp(&list->comm1);
		return (error_mg("malloc_error"));
	}
	list->path = split_c(tmp, ':');
	if (list->path == NULL)
	{
		free_sp(&list->comm1);
		free_sp(&list->comm2);
		return (error_mg("malloc_error"));
	}
	return (1);
}

int	cmd_ch(char **argv, char *envp, t_box *list)
{
	char	*tmp;

	tmp = copy_envp(envp);
	if (tmp == NULL)
		return (error_mg("malloc_error"));
	if (!sp_main(argv, tmp, list))
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	if (!check_arg1(list))
	{
		if (!a_access(list))
			return (sp_error(argv[2]));
	}
	if (!check_arg2(list))
	{
		if (!b_access(list))
			return (sp_error(argv[3]));
	}
	return (1);
}

int	open_file(char **argv, t_box *list)
{
	list->infile = open(argv[1], O_RDONLY);
	list->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (list->infile < 0 && list->outfile < 0)
	{
		error_mg("infile_error");
		error_mg("outfile_error");
		list_free(list);
		return (0);
	}
	else if (list->infile < 0)
	{
		free_perror("infile_error", list);
		return (0);
	}
	else if (list->outfile < 0)
	{
		free_perror("outfile_error", list);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_box	list;
	int		i;

	i = 0;
	if (argc != 5)
		return (ew_mg("input_error\n"));
	while (envp[i] != '\0' && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (envp[i] == '\0')
		return (check_pa(&list, argv, envp));
	if (!cmd_ch(argv, envp[i], &list))
		return (1);
	if (!open_file(argv, &list))
		return (1);
	if (!pipex(&list, envp))
		return (1);
	list_free(&list);
	return (0);
}
