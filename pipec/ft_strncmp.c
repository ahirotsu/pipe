/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 21:16:12 by ahirotsu          #+#    #+#             */
/*   Updated: 2024/02/15 18:02:39 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*k;
	unsigned char	*p;

	i = 0;
	k = (unsigned char *)s1;
	p = (unsigned char *)s2;
	while (i < n)
	{
		if (k[i] != p[i])
		{
			return (k[i] - p[i]);
		}
		if (k[i] == '\0' || p[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return (0);
}
