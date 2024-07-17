/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 21:59:05 by ahirotsu          #+#    #+#             */
/*   Updated: 2024/06/08 00:19:42 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>

# define R 0
# define W 1

typedef struct a_list
{
	int		infile;
	int		outfile;
	int		fd[2];
	char	**comm1;
	char	**comm2;
	char	**path;
	char	*a_path;
	char	*b_path;
}	t_box;

int		error_mg(char *str);
int		ew_mg(char *str);
int		free_perror(char *str, t_box *list);
char	**free_sp(char ***split);
char	**split_c(char const *s, char c);
int		a_access(t_box *list);
int		b_access(t_box *list);
int		pipex(t_box *list, char **envp);
void	list_free(t_box *list);
void	three_free(t_box *list);
int		check_arg1(t_box *list);
int		check_arg2(t_box *list);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		check_pa(t_box *list, char **argv, char **envp);
int		sp_error(char *argv);

#endif
