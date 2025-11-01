/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:18:13 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/23 10:36:23 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static size_t	ft_wordcount(const char *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else if (*s != c)
		{
			while (*s != c && *s)
				s++;
			words++;
		}
		else
			s++;
	}
	return (words);
}

static size_t	ft_strnlen(const char *s, size_t n)
{
	const char	*p;

	if (n == 0)
		return (0);
	p = s;
	while (*p && n--)
		p++;
	return (p - s);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	char	*start;

	if (n == 0)
		return (NULL);
	dup = malloc((ft_strnlen(s, n) + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	start = dup;
	while (*s != '\0' && n--)
		*dup++ = *(char *)s++;
	*dup = '\0';
	return (start);
}

static char	**free_list(char **s)
{
	char	**start;

	start = s;
	while (*s != NULL)
	{
		free(*s);
		++s;
	}
	free(start);
	return (NULL);
}

/**
 * @brief splits the string at each 'c' (malloc)
 * 
 * @param s string to split
 * @param c the delimeter
 * @return char** returns an array that contains the split strings
 */
char	**ft_split(char const *s, char c)
{
	char		**splitarr;
	const char	*start;	
	size_t		index;

	index = 0;
	splitarr = malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (splitarr == NULL)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s != c && *s)
				s++;
			splitarr[index++] = ft_strndup(start, (s - start));
			if (splitarr[index - 1] == NULL)
				return (free_list(splitarr));
		}
		else
			s++;
	}
	splitarr[index] = NULL;
	return (splitarr);
}

// int main(void)
// {
// 	char *s = "xxxxxxxxxxxxxxxhello!";
// 	char c = 'x';
// 	int	i;	
// 	char **arr = ft_split("--1-2--3---4----5-----42", '-');	
// 	i = 0;
// 	while (arr[i])
// 	{
// 		printf("%s\n", arr[i]);
//      	free(arr[i]);
// 		i++;
// 	}
// 	printf("%s\n", arr[i]);
// 	free(arr);		
// }