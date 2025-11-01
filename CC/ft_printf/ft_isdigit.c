/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:00:10 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/17 10:11:10 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

// #include <stdio.h>
// int main(void)
// {
//     int c = 1;

//     if(ft_isdigit(c))
//     {
//         printf("It's a digit");
//     }
//     else{
//         printf("Not a digit");
//     }
// }