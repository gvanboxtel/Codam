/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:03:52 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/15 11:48:56 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int main(void)
// {
// 	char c = 'c';
// 	int fd = 2;	
// 	ft_putchar_fd(c, fd);
// }