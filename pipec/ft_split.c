/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:29:56 by ahirotsu          #+#    #+#             */
/*   Updated: 2024/02/15 18:02:27 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**free_split(char ***split)
{
	int	i;

	i = 0;
	while ((*split)[i] != NULL)
	{
		free((*split)[i]);
		(*split)[i] = NULL;
		i++;
	}
	free(*split);
	*split = NULL;
	return (NULL);
}

static unsigned int	count_words(char const *str, char c)
{
	unsigned int	word;
	unsigned int	i;

	if (str[0] == '\0')
		return (0);
	i = 1;
	word = 0;
	if (str[0] != c)
		word++;
	while (str[i] != '\0')
	{
		if (str[i] != c && str[i - 1] == c)
			word++;
		i++;
	}
	return (word);
}

static void	copy_one_word(char *dst, char const *src, char c)
{
	unsigned int	i;

	i = 0;
	while (src[i] != c && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

static int	copy_words(char const *str, char c, char **dst)
{
	unsigned int	word;
	unsigned int	letter;
	unsigned int	i;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			letter = 0;
			while (str[i + letter] != c && str[i + letter] != '\0')
				letter++;
			dst[word] = malloc(sizeof(char) * (letter + 1));
			if (dst[word] == NULL)
				return (0);
			copy_one_word(dst[word], str + i, c);
			word++;
			i = i + letter;
		}
		else
			i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		word_count;

	if (s == NULL)
		return (NULL);
	word_count = count_words(s, c);
	if (word_count == 0)
		return (0);
	result = malloc(sizeof(char *) * (word_count + 1));
	if (result == NULL)
		return (NULL);
	result[word_count] = NULL;
	if (!copy_words(s, c, result))
		return (free_split(&result));
	return (result);
}
