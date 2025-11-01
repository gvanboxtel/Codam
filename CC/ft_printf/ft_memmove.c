/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 09:56:50 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/22 17:57:06 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/**
 * @brief copies n bytes from src to dest, memory may overlap
 * 
 * @param dest string to be moved into
 * @param src original string
 * @param n limit to move
 * @return void* returns the const void* dest
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if (s < d)
	{
		s += n;
		d += n;
		while (n--)
			*--d = *--s;
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
	return (dest);
}

// #include <stdio.h>

// int main(void)
// {
// 	char src[50] = "abcdef";
// 	char *dest = &src[1];

// 	ft_memmove(dest, src, sizeof(dest));
// 	printf("%s\n", dest);
// }