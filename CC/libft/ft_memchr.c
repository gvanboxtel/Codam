/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:23:42 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/22 17:53:19 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/**
 * @brief tries to find the first instance of 'c' in const void* s upto n bytes
 * 
 * @param s const void *s
 * @param c int c to find
 * @param n limit
 * @return void* returns the point where 'c' is found
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;

	p = s;
	while (n--)
	{
		if (*p == (unsigned char)c)
			return ((void *)p);
		p++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//     char *s = "dsgfsa";
//     int c = '\0';
//     char *p;
// 	char *x;

//     p = ft_memchr(s, c, (strlen(s) + 1));
//     if (p)
//         printf("Found '%c' at position %ld\n", *p, p - s);
//     else
//         printf("Not found\n");

// }