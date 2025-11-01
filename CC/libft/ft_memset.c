/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:17:52 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/22 15:26:35 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/**
 * @brief sets memory of s to 'c' up to size n
 * 
 * @param s void * (could be anything)
 * @param c int 'c' to replace the stuff in s
 * @param n limit of memory to set
 * @return void* return the void *s with memory set by 'c'
 */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*cast;	

	cast = (unsigned char *)s;
	while (n--)
		*cast++ = (unsigned char)c;
	return (s);
}

// #include <stdio.h>
// int main()
// {
//     char str[50] = ".....................";
//     printf("\nBefore memset(): %s\n", str);
//     ft_memset(str, 'g', 4);
//     printf("After memset():  %s", str);
//     return 0;
// }