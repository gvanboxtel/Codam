/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:18:18 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/22 18:38:31 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include <string.h>

/**
 * @brief find 'c'  in string starting from the beginning
 * 
 * @param s string
 * @param c int c to be found in c 
 * @return char* return string from the point you find 'c'
 */
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

// #include <stdio.h>
// int main(void)
// {
// 	int c;
// 	char *s = "teste";
// 	c = 'e';	
// 	//printf("%s\n",ft_strchr(s, c));
// 	printf("%s", strchr(s, c));
// 	return (0);
// }