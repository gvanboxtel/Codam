/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:37:34 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/22 15:14:23 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/**
 * @brief copies string into destination up to size and returns srclen
 * 
 * @param dst string in which the copy is put
 * @param src original string
 * @param size limit of copy
 * @return size_t return the size of the copy it tried to create (srclen)
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;	

	d = dst;
	s = src;
	if (size > 0)
	{
		size = size -1;
		while (size-- && *s)
			*d++ = *s++;
		*d = '\0';
	}
	return (ft_strlen(src));
}

// #include <stdio.h>
// int main(void)
// {
// 	char *s = "abcdef";
// 	char d[50];

// 	ft_strlcpy(d,s,sizeof(d));
// 	printf("%zu", ft_strlcpy(d,s,sizeof(d)));
// 	//printf("%s\n", d);
// }