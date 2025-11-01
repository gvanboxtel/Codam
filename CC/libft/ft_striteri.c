/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:00:01 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/22 15:18:56 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

// void to_upper_even(unsigned int i, char *s)
// {
//     if (i % 2 == 0 && *s >= 'a' && *s <= 'z')
//         *s -= 32;
// }

/**
 * @brief iterates through a string and applies a function
 * 
 * @param s string
 * @param f function
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t		i;

	i = 0;
	while (*s)
		f(i++, s++);
}

// int main(void)
// {
//     char str[] = "Hallo, How is it going?";    

//     printf("Original: %s\n", str);
// 	ft_striteri(str, to_upper_even);  
// 	printf("Changed: %s\n", str);

//     return (0);
// }