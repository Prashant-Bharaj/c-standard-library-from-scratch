/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:54:49 by prasingh          #+#    #+#             */
/*   Updated: 2025/11/21 20:01:39 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_substr(const char *s, unsigned int start, size_t len)
{
    char    *substr;
    size_t  i;
    size_t  s_len;

    s_len = 0;
    while (s[s_len] != '\0')
        s_len++;
    // if index start is greater than string length, return empty string
    // because there's nothing to copy
    // why not just return NULL? because NULL indicates an error in allocation
    if (start >= s_len)
        return (char *)malloc(1);
    if (len > s_len - start)
        len = s_len - start;
    substr = (char *)malloc((len + 1) * sizeof(char));
    // not enough memory
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
