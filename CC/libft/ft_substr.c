/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:19:00 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/23 09:43:10 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

/**
 * @brief create substring from string (malloc)
 * 
 * @param s original string
 * @param start start of substring
 * @param len length up to which to copy from string
 * @return char* the substring or NULL if fails
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	lenstr;

	lenstr = ft_strlen(s);
	if (start >= lenstr)
		return (ft_strdup(""));
	if (len > lenstr - start)
		len = lenstr - start;
	substr = malloc((len + 1) * sizeof(char));
	if (substr != NULL)
		ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}

// int main(void)
// {
// 	char *s = "How is it going";
// 	int start = 3254324;
// 	size_t len = 0;
// 	printf("%s\n", ft_substr(s,start,len));	
// }