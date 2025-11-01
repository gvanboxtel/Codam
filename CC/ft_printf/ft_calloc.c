/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:17:26 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/22 19:10:57 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>
#include <stdlib.h>
#include <stdint.h>
#include "libft.h"

/**
 * @brief malloc but then set the newly created pointer to all \0 (malloc)
 * 
 * @param nmemb numer of elements
 * @param size sizeof elements in bytes
 * @return void* return the dynamic pointer with \0 memory alloc
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*arr;

	if (nmemb == 0 || size == 0 || (nmemb > SIZE_MAX / size))
		return (malloc(0));
	arr = malloc(nmemb * size);
	if (arr == NULL)
		return (arr);
	ft_bzero(arr, (nmemb * size));
	return (arr);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main() {
//     int *ptrA = (int *)ft_calloc(INT_MAX, INT_MAX);
// 	int *ptrB = (int *)calloc(INT_MAX, INT_MAX);  
//     // Checking if failed or pass
//     if (ptrA == NULL && ptrB == NULL ) {
//         printf("Allocation Failed");
//         exit(0);
//     }	   
//     // No need to populate as already
//     // initialized to 0        
//     // Print the array
//     printf("%d ptraA\n", *ptrA);
// 	printf("%d ptrB\n", *ptrB);	
//     return 0;
// }