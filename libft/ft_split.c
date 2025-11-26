/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:51:09 by prasingh          #+#    #+#             */
/*   Updated: 2025/11/23 15:15:21 by prasingh         ###   ########.fr       */
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

char	**ft_split(const char *s, char c)
{
	const char	*start;
	char		**result;
	int			index;

	if (s == NULL)
		return (NULL);
	start = s;
	index = 0;
	result = (char **)malloc((count_splits(s, c) + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == c)
		{
			if (start != s)
				result[index++] = ft_substr(start, 0, s - start);
			start = s + 1;
		}
		s++;
	}
	if (start != s)
		result[index++] = ft_substr(start, 0, s - start);
	result[index] = NULL;
	return (result);
}
