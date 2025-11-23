/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:59:21 by prasingh          #+#    #+#             */
/*   Updated: 2025/11/23 10:59:33 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list *ft_lstlast(t_list *lst)
{
    if (lst == NULL)
        return NULL;
    while (lst->next != NULL)
    {
        lst = lst->next;
    }
    return lst;
}
