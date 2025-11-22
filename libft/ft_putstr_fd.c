/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:55:52 by prasingh          #+#    #+#             */
/*   Updated: 2025/11/22 16:56:01 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putstr_fd(const char *s, int fd)
{
    if (s == NULL)
        return ;
    while (*s)
    {
        ft_putchar_fd(*s, fd);
        s++;
    }
}
