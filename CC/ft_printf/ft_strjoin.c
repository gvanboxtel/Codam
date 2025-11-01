/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:18:29 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/23 10:12:35 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "libft.h"

/**
 * @brief joins two strings together (malloc)
 * 
 * @param s1 
 * @param s2 
 * @return char* returns the joined strings in one string
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*catstr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	catstr = malloc(((ft_strlen(s1)) + (ft_strlen(s2) + 1)));
	if (catstr == NULL)
		return (NULL);
	ft_strlcpy(catstr, s1, ft_strlen(s1) + 1);
	ft_strlcat(catstr, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (catstr);
}

// int main(void)
// {
// 	char *s1 = "Tripouille";
// 	char *s2 = "42";
// 	printf("%s\n", ft_strjoin(s1, s2));
// }	
