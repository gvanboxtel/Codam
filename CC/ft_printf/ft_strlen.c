/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:37:02 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/23 10:05:20 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	const char	*iterator;

	iterator = s;
	while (*iterator)
		iterator++;
	return (iterator - s);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *s = "abc";

// 	printf("%zu", ft_strlen(s));
// }