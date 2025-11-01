/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:27:30 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/22 17:46:58 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/**
 * @brief sets void *s to all \0 up to n
 * 
 * @param s void *s (string or whatever)
 * @param n limit of n bytes
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

// #include <stdio.h>

// int main()
// {
//     char str[50] = "Greetings, Traveller!";
//     // Fill 8 characters starting from str[13] with '.'
//     ft_bzero(str + 6, sizeof(char));  
// 	printf("%s\n",str);  
//     return 0;
// }