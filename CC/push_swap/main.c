/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:08:27 by gvan-box          #+#    #+#             */
/*   Updated: 2025/12/12 10:56:12 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"

#include <stdio.h>

int *make_list(int counter, char **argv)
{
	int *list;
	int i;

	i = 0;
	list = ft_calloc(counter, sizeof(int));
	if (!list)
		return (NULL);
	while (i != counter)
	{
		list[i] = ft_atoi(argv[i+1]);
		i++;
	}
	return (list);
}

