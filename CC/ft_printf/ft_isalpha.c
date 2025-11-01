/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:51:57 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/17 12:36:46 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// #include <stdio.h>
// int main(void)
// {
//     char c = ')';

//     if(ft_isalpha(c))
//     {
//         printf("It's a letter");
//     }
//     else{
//         printf("Not a letter");
//     }
// }