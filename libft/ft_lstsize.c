/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:51:11 by prasingh          #+#    #+#             */
/*   Updated: 2025/11/23 10:53:12 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int ft_lstsize(t_list *lst)
{
    int len;

    len = 0;
    while(lst)
    {
        len++;
        lst = lst->next;
    }
    return len;
}
