/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 19:17:45 by prasingh          #+#    #+#             */
/*   Updated: 2025/11/20 19:18:35 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	while (dst[dst_len] != '\0' && dst_len < dstsize)
		dst_len++;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (dst_len == dstsize)
		return (dstsize + src_len);
	i = 0;
	while (src[i] != '\0' && (dst_len + i + 1) < dstsize)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len + i < dstsize)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
