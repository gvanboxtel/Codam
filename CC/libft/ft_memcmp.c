/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:31:25 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/22 17:53:54 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/**
 * @brief same as strmcp but instead limited by n not \0
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @return int returns differnce s1-s2 if there is any
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = s1;
	p2 = s2;
	if (n == 0 || s1 == s2)
		return (0);
	while (--n && *p1 == *p2)
	{
		++p1;
		++p2;
	}
	return (*p1 - *p2);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char s1[] = "abc";
// 	char s2[] = "abc";
// 	printf("%d\n", ft_memcmp(s1,s2,7));
// 	printf("%d", memcmp(s1,s2,7));	
// 	return (0);	
// }