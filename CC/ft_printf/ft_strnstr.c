/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:18:41 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/22 15:04:49 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "libft.h"

/**
 * @brief find little string in big string up to defined length
 * 
 * @param big the original string in which to find little
 * @param little the string to find in big
 * @param len the max length to find little in big
 * @return char* return the beginning of big from where little is found
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*b;
	const char	*l;
	size_t		n;

	if (!*little)
		return ((char *)big);
	while (*big && len)
	{
		b = big;
		l = little;
		n = len;
		while (*l && *b && *b == *l && n--)
		{
			++b;
			++l;
		}
		if (!*l)
			return ((char *)big);
		++big;
		--len;
	}
	return (NULL);
}

// #include <string.h>
// int main(void)
// {
// 	char *big = "aaxaxx";
// 	char *little = "xx";
// 	size_t max = strlen(big);
// 	char *s1 = strstr(big, little);
// 	char *s2 = ft_strnstr(big, little, max);
// 	printf("%s\n%s\n", s1, s2);
// }