/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:52:38 by ahirotsu          #+#    #+#             */
/*   Updated: 2024/02/15 18:13:45 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *s1)
{
	int		s1_l;
	int		i;
	char	*cp;

	i = 0;
	s1_l = ft_strlen(s1);
	cp = (char *)malloc(sizeof(char) * s1_l + 1);
	if (cp == NULL)
		return (0);
	while (s1[i] != '\0')
	{
		cp[i] = s1[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
