/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:18:46 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/23 09:51:04 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief find 'c'  in string starting from the back
 * 
 * @param s string
 * @param c int c to be found in c 
 * @return char* return string from the point you find 'c'
 */
char	*ft_strrchr(const char *s, int c)
{
	const char	*end;

	end = s + (ft_strlen(s));
	if (c == '\0')
		return ((char *)end);
	while (end-- > s)
	{
		if (*end == (char)c)
			return ((char *)end);
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	int c;
// 	char *s = "teste";
// 	c = '\0';	
// 	printf("%s\n",ft_strrchr(s, c));
// 	printf("%s\n",strrchr(s, c));	
// }