/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:51:09 by prasingh          #+#    #+#             */
/*   Updated: 2025/11/22 15:19:05 by prasingh         ###   ########.fr       */
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
	const char	*end;
	char		**result;
	int			index;

	start = s;
	index = 0;
	result = (char **)malloc((count_splits(s, c) + 1) * sizeof(char *));
	while (*s)
	{
		if (*s == c)
		{
			end = s;
			if (start != end)
				result[index++] = ft_substr(start, 0, end - start);
			start = s + 1;
		}
		s++;
	}
	if (*s == '\0' && start != s)
		result[index++] = ft_substr(start, 0, end - start);
	result[index] = NULL;
	return (result);
}
