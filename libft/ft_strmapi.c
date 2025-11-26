/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:23:17 by prasingh          #+#    #+#             */
/*   Updated: 2025/11/22 16:27:44 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*mapped;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	mapped = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (mapped == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		mapped[i] = f(i, s[i]);
		i++;
	}
	mapped[i] = '\0';
	return (mapped);
}
