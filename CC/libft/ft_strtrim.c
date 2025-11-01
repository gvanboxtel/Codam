/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:18:53 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/22 15:11:25 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

/**
 * @brief trim beginning and end until non set char (malloc)
 * 
 * @param s1 original string
 * @param set set of characters that you want to trim of
 * @return char* malloc of original string without set characters
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*start;
	const char	*end;
	char		*trimmed;
	size_t		len;

	start = s1;
	end = s1 + (ft_strlen(s1) - 1);
	while (*start && ft_strchr(set, *start))
		start++;
	while (end > start && ft_strchr(set, *end))
		end--;
	len = (end - start) + 1;
	trimmed = malloc((len + 1) * sizeof(char));
	if (trimmed == NULL)
		return (NULL);
	ft_memcpy(trimmed, start, len);
	trimmed[len] = '\0';
	return (trimmed);
}

// int main(void)
// {
//     char *s1 = "";
//     char *set = "";
//     printf("%s\n", ft_strtrim(s1, set));
// }
