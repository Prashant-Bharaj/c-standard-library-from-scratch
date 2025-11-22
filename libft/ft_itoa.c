/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 15:23:34 by prasingh          #+#    #+#             */
/*   Updated: 2025/11/22 15:26:19 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_itoa(int n)
{
    char    *str;
    long    num;
    size_t  len;
    int     negative;

    negative = 0;
    num = n;
    if (num < 0)
    {
        negative = 1;
        num = -num;
    }
    len = 1 + negative; // at least one digit + sign if negative
    long temp = num;
    while (temp >= 10)
    {
        temp /= 10;
        len++;
    }
    str = (char *)malloc((len + 1) * sizeof(char));
    if (str == NULL)
        return (NULL);
    str[len] = '\0';
    while (len > 0)
    {
        str[--len] = (num % 10) + '0';
        num /= 10;
    }
    if (negative)
        str[0] = '-';
    return (str);
}
