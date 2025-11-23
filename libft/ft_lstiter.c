/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 11:43:53 by prasingh          #+#    #+#             */
/*   Updated: 2025/11/23 11:46:04 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void ft_lstiter(t_list *lst, void (*f)(void *))
{
    while (lst != NULL)
    {
        f(lst->content);
        lst = lst->next;
    }
}
