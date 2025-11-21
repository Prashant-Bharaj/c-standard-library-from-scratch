/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:23:48 by prasingh          #+#    #+#             */
/*   Updated: 2025/11/21 14:25:04 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *ft_strrchr(const char *s, int c)
{
    const char  *last_occurrence;

    last_occurrence = NULL;
    while (*s)
    {
        if (*s == (char)c)
            last_occurrence = s;
        s++;
    }
    if (c == '\0')
        return ((char *)s);
    return ((char *)last_occurrence);
}
