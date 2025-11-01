/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:32:52 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/21 14:53:25 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <ctype.h>
#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

// #include <stdio.h>
// int main(void)
// {
//     int c = -1;

//     if(ft_isprint(c))
//     {
//         printf("It's printable\n");
//     }
//     else{
//         printf("Not printable\n");
//     }

// 	if(isprint(c))
//     {
//         printf("It's printable\n");
//     }
//     else{
//         printf("Not printable\n");
//     }
// }