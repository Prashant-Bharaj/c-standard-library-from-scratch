/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:54:22 by prasingh          #+#    #+#             */
/*   Updated: 2025/11/20 16:01:41 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_bzero(void *s, size_t n)
{
    unsigned char   *ptr;
    size_t          i;

    ptr = (unsigned char *)s;
    i = 0;
    while (i < n)
    {
        ptr[i] = 0;
        i++;
    }
}
