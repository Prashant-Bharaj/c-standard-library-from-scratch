/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:21:17 by prasingh          #+#    #+#             */
/*   Updated: 2025/11/22 17:24:09 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putendl_fd(const char *s, int fd)
{
    if (s == NULL)
        return ;
    ft_putstr_fd(s, fd);
    ft_putchar_fd('\n', fd);
}
