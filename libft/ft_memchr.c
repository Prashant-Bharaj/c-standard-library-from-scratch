/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:33:28 by prasingh          #+#    #+#             */
/*   Updated: 2025/11/21 17:57:27 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	uc;
	unsigned char	*ptr;

	uc = (unsigned char)c;
	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == uc)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}
