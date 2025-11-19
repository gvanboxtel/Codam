/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:07:06 by gvan-box          #+#    #+#             */
/*   Updated: 2025/11/19 12:21:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	const char	*iterator;
	if (!s)
		return (0);
	iterator = s;
	while (*iterator)
		iterator++;
	return (iterator - s);
}

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

char	*ft_strchr(const char *s, int c, size_t *len)
{
	while (*s)
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
		(*len)++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
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

char	*ft_strjoin(char const *s1, char const *s2, int char_read)
{
	char	*catstr;

	if (s2 == NULL)
		return (NULL);
	catstr = malloc(((ft_strlen(s1)) + (char_read + 1)));
	if (catstr == NULL)
		return (free((void *)s1), NULL);
	ft_strlcpy(catstr, s1, ft_strlen(s1) + 1);	
	ft_strlcat(catstr, s2, ft_strlen(s1) + char_read + 1);	
	return (free((void *)s1), catstr);
}

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
