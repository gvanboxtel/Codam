/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:17:21 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/20 12:17:23 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}

// #include <stdio.h>
// int main(void)
// {
//     int c = 1;

//     if(ft_isalnum(c))
//     {
//         printf("It's alhpanumeric");
//     }
//     else{
//         printf("Not alphanumeric");
//     }
// }