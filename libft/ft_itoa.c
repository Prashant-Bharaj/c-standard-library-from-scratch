/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 15:23:34 by prasingh          #+#    #+#             */
/*   Updated: 2025/11/23 13:45:15 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill_string(char *str, long num, size_t len, int negative)
{
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	if (negative)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	size_t	len;
	int		negative;
	long	temp;

	negative = 0;
	num = n;
	if (num < 0)
	{
		negative = 1;
		num = -num;
	}
	len = 1 + negative;
	temp = num;
	while (temp >= 10)
	{
		temp /= 10;
		len++;
	}
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	fill_string(str, num, len, negative);
	return (str);
}
