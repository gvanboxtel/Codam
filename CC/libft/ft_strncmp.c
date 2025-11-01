/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:17:39 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/22 15:06:41 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/**
 * @brief compare two strings up to n bytes
 * 
 * @param s1 string 1 to compare
 * @param s2 strin 2 to compare
 * @param n limit
 * @return int difference of ascii code (s1-s2)
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (--n && *s1 && *s2 && *(unsigned char *)s1 == *(unsigned char *)s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char s1[] = "abcdef";
// 	char s2[] = "ab\375xx";
// 	printf("%d\n", ft_strncmp(s1,s2,5));
// 	printf("%d", strncmp(s1,s2,5));
// 	return (0);
// }