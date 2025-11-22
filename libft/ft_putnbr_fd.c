/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:34:26 by prasingh          #+#    #+#             */
/*   Updated: 2025/11/22 17:39:21 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
    long num;

    num = n;
    if (num < 0)
    {
        ft_putchar_fd('-', fd);
        if(num == -2147483648)
        {
            // handle edge case for INT_MIN
            ft_putchar_fd('2', fd);
            num = 147483648;
        }
        else
            num = -num;
    }
    if (num >= 10)
    {
        ft_putnbr_fd(num / 10, fd);
    }
    ft_putchar_fd((num % 10) + '0', fd);
}
