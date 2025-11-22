/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:13:55 by prasingh          #+#    #+#             */
/*   Updated: 2025/11/22 14:46:56 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t trimed_len(const char *s1, const char *set)
{
    size_t  len;
    const char  *start;
    const char  *end;

    start = s1;
    while (*start)
    {
        if (ft_strchr(set, *start) == NULL)
            break;
        start++;
    }
    end = s1 + ft_strlen(s1) - 1;
    while (end > start)
    {
        if (ft_strchr(set, *end) == NULL)
            break;
        end--;
    }
    len = (end >= start ? (size_t)(end - start + 1) : 0);
    return (len);
}

static const char *trimed_start(const char *s1, const char *set)
{
    while(*s1)
    {
        if (ft_strchr(set, *s1) == NULL)
            break;
        s1++;
    }
    return (s1);
}

char *ft_strtrim(const char *s1, const char *set)
{
    return (ft_substr(trimed_start(s1, set),
            0,
            trimed_len(s1, set)));
}
