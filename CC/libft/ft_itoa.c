/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:17:11 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/23 09:42:27 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "libft.h"

static char	*ft_getstr(int n, size_t *len)
{
	size_t	length;

	length = 0;
	if (n < 0 || n == 0)
		length++;
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	*len = length;
	return (malloc((length + 1) * sizeof(char)));
}

/**
 * @brief sets integer to string
 * 
 * @param n integer to convert
 * @return char* returns the string
 */
char	*ft_itoa(int n)
{
	int		sign;	
	char	*s;
	size_t	len;

	s = ft_getstr(n, &len);
	if (s == NULL)
		return (NULL);
	sign = 1;
	if (n < 0)
	{
		*s = '-';
		sign = -1;
	}
	if (n == 0)
		*s = '0';
	*(s + len) = '\0';
	while (n != 0)
	{
		*(s + --len) = ((n % 10) * sign) + '0';
		n /= 10;
	}
	return (s);
}

// int main(void)
// {
// 	int i = INT_MIN;	
// 	printf("%d\n", i);
// 	printf("%s\n", ft_itoa(i));	
// }