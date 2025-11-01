/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:36:18 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/22 18:35:58 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

/**
 * @brief duplicates a string in a malloc copy (malloc)
 * 
 * @param s string to duplicate
 * @return char* return the duplicated string
 */
char	*ft_strdup(const char *s)
{
	char	*dup;

	dup = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (dup != NULL)
		ft_strlcpy(dup, s, ft_strlen(s) + 1);
	return (dup);
}

// int main (void)
// {
// 	char *src = "JGKYUGYU$*#(*BF\n\v)";	
// 	printf("%s\n", ft_strdup(src));		
// }