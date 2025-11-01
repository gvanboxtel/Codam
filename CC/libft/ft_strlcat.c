/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:50:53 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/22 15:16:00 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/**
 * @brief concatenates two strings into dest up to size 
 * 
 * @param dst string (+ src)
 * @param src string to add
 * @param size limit up to which to concatenate
 * @return size_t return size of the string it tried to concatenate
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		n;
	size_t		dlen;

	d = dst;
	s = src;
	n = size;
	while (n-- && *d)
		d++;
	dlen = d - dst;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(src));
	while (--n && *s)
		*d++ = *s++;
	*d = '\0';
	return (dlen + ft_strlen(src));
}

// #include <stdio.h>
// int main(void)
// {
// 	char *s = "Hoe is het";
// 	char d[1] = "Hoi";

// 	//ft_strlcat(d,s,sizeof(d));
// 	printf("%zu", ft_strlcat(d,s,sizeof(d)));
// 	//printf("%s\n", d);
// 	return (0);
// }