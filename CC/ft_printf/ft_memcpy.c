/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:17:45 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/23 10:15:09 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/**
 * @brief copies src into dst up to size n
 * 
 * @param dest string to be copied into
 * @param src main string
 * @param n limit
 * @return void* returns the copy of the string in dest
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char *dest = NULL;
// 	char *src = NULL;
	// ft_memcpy(NULL, NULL, 3);
	// printf("%s\n", dest); // Prints "abc"
	// for (int i = 0; i < 7; i++)
	// 	printf("%02x ", (unsigned char)dest[i]); // Shows all bytes including 0
	// memcpy(NULL, NULL, 3);
	// printf("%s\n", dest); // Prints "abc"
	// for (int i = 0; i < 7; i++)
	// 	printf("%02x ", (unsigned char)dest[i]); // Shows all bytes including 0
//}
