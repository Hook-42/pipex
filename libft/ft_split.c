/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 09:48:26 by hook              #+#    #+#             */
/*   Updated: 2022/06/06 09:29:56 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	ft_free_all(char **tab, int word)
{
	while (word >= 0)
	{
		free(tab[word]);
		word--;
	}
	free(tab);
}

static size_t	ft_count_words(char const *s, char c)
{
	int		i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i + 1] == '\0')
			return (words + 1);
		if (s[i] == c && s[i + 1] != c)
			words++;
		i++;
	}
	return (words + 1);
}

static int	ft_count_letter(char const *s, char c, int i)
{
	int	cpt;

	cpt = 0;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (cpt);
		i++;
		cpt++;
	}
	return (cpt + 1);
}

static char	**ft_norm(char const *s, char c, char **split, int letter)
{
	int	split_word;
	int	split_letter;

	split_word = 0;
	while (s[letter])
	{
		if (s[letter] != c)
		{
			split_letter = -1;
			split[split_word] = malloc(sizeof(char)
					* ft_count_letter(s, c, letter) + 1);
			if (!split[split_word])
			{
				ft_free_all(split, split_word);
				return (NULL);
			}
			while (s[letter] != c && s[letter])
				split[split_word][++split_letter] = s[letter++];
			split[split_word][++split_letter] = '\0';
			split_word++;
		}
		else
			letter++;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		split_word;
	int		letter;

	letter = 0;
	while (s[letter] == c)
		letter++;
	if (!s || s[0] == '\0' || (size_t)letter == ft_strlen(s))
	{
		split = malloc(sizeof(char *) * 1);
		if (!split)
			return (NULL);
		split[0] = NULL;
		return (split);
	}
	letter = 0;
	split_word = (ft_count_words(s, c));
	split = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!split)
		return (NULL);
	if (!ft_norm(s, c, split, letter))
		return (NULL);
	split[split_word] = NULL;
	return (split);
}
