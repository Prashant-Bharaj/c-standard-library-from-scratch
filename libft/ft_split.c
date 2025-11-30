/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:51:09 by prasingh          #+#    #+#             */
/*   Updated: 2025/11/30 21:43:55 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_splits(const char *s, char c)
{
	size_t	count;
	int		in_substring;

	count = 0;
	in_substring = 0;
	while (*s)
	{
		if (*s != c && in_substring == 0)
		{
			in_substring = 1;
			count++;
		}
		else if (*s == c)
		{
			in_substring = 0;
		}
		s++;
	}
	return (count);
}

static void	free_splits(char **arr, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	add_word(char **result, int *index, const char *start, size_t len)
{
	char	*word;

	word = ft_substr(start, 0, len);
	if (word == NULL)
		return (0);
	result[(*index)++] = word;
	return (1);
}

static int	fill_splits(char **result, const char *s, char c)
{
	const char	*start;
	int			index;

	start = s;
	index = 0;
	while (*s)
	{
		if (*s == c)
		{
			if (start != s && !add_word(result, &index, start, s - start))
			{
				free_splits(result, index);
				return (0);
			}
			start = s + 1;
		}
		s++;
	}
	if (start != s && !add_word(result, &index, start, s - start))
	{
		free_splits(result, index);
		return (0);
	}
	result[index] = NULL;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**result;

	if (s == NULL)
		return (NULL);
	result = malloc((count_splits(s, c) + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	if (!fill_splits(result, s, c))
		return (NULL);
	return (result);
}
