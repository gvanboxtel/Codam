/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:27:34 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/22 15:12:10 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

// char    to_upper_even(unsigned int i, char c)
// {
//     if (i % 2 == 0 && c >= 'a' && c <= 'z')
//         return (c - 32);
//     return (c);
// }

/**
 * @brief maps function onto a string (malloc)
 * 
 * @param s string
 * @param f function
 * @return char* returns the functioned string
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*result;
	size_t		i;
	char		*start;

	i = 0;
	result = malloc((ft_strlen(s) +1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	start = result;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (start);
}

// int main(void)
// {
//     char *str = "Hallo, How is it going?";
//     char *result;

//     result = ft_strmapi(str, to_upper_even);
//     if (result == NULL)
// 		return (1);
//     printf("Original: %s\n", str);
//     printf("Mapped:   %s\n", result);

//     free(result);
//     return (0);
// }