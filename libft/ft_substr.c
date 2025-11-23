/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:54:49 by prasingh          #+#    #+#             */
/*   Updated: 2025/11/23 13:30:41 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*empty_string(void)
{
	char	*str;

	str = (char *)malloc(1);
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	s_len = 0;
	while (s[s_len] != '\0')
		s_len++;
	if (start >= s_len)
		return (empty_string());
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
