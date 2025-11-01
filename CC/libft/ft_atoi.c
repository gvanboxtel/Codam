/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:54:17 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/23 10:40:46 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>
#include "libft.h"

/**
 * @brief string to int
 *
 * @param nptr string with number
 * @return int return int number
 */
int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	sign = 1;
	result = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// int main()
// {
// 	char	n[40] = "2147483649";
//     int res_val;
//     char inp_str[30];
//     // Initializing the input string
//     strcpy(inp_str, "+++++++++++");
//     // Convert string to integer using atoi() and store the
//     // result in result_value
//     // res_val = ft_atoi(NULL);
//     // printf("Input String = %s\nResulting Integer (ft_atoi:) = %d\n
//Resulting Integer (atoi:) = %d\n",
//     //        n, res_val, atoi(NULL));
// 	printf("%i", ft_atoi(NULL));
//     return 0;
// }