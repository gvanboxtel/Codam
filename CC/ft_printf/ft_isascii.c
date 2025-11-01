/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:28:48 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/17 12:37:06 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

// #include <stdio.h>
// int main(void)
// {
//     size_t c = 1;

//     if(ft_isascii(c))
//     {
//         printf("It's an ascii");
//     }
//     else{
//         printf("Not an ascii");
//     }
// }