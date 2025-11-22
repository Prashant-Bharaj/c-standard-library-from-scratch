/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 11:58:33 by prasingh          #+#    #+#             */
/*   Updated: 2025/11/22 11:59:23 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *ft_strjoin(const char *s1, const char *s2)
{
    char    *joined;
    size_t  i;
    size_t  j;
    size_t  len1;
    size_t  len2;

    len1 = 0;
    while (s1[len1] != '\0')
        len1++;
    len2 = 0;
    while (s2[len2] != '\0')
        len2++;
    joined = (char *)malloc((len1 + len2 + 1) * sizeof(char));
    if (joined == NULL)
        return (NULL);
    i = 0;
    while (i < len1)
    {
        joined[i] = s1[i];
        i++;
    }
    j = 0;
    while (j < len2)
    {
        joined[i + j] = s2[j];
        j++;
    }
    joined[i + j] = '\0';
    return (joined);
}
