/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 18:35:17 by prasingh          #+#    #+#             */
/*   Updated: 2025/11/21 18:36:08 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(const char *nptr)
{
    int     sign;
    long    result;
    size_t  i;

    sign = 1;
    result = 0;
    i = 0;
    while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
        i++;
    if (nptr[i] == '+' || nptr[i] == '-')
    {
        if (nptr[i] == '-')
            sign = -1;
        i++;
    }
    while (nptr[i] >= '0' && nptr[i] <= '9')
    {
        result = result * 10 + (nptr[i] - '0');
        i++;
    }
    return ((int)(result * sign));
}
