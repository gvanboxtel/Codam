/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:08:27 by gvan-box          #+#    #+#             */
/*   Updated: 2025/12/08 17:08:09 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"


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

int main_test(int argc, char **argv)
{
	int i;
	int *list_a;
	int *list_b;

	i = 1;
	if (argc > 1)
	{
		while (i < argc && argv[i][0])
		{
			if (ft_isdigit(argv[i][0]))
				;
			else
			{
				write(2, "Error: Not a valid input\n", 25);
				exit (1);
			}
			i++;
		}
	}
	else
	{
		write(2, "Error: No arguments were provided\n", 34);
		exit (1);
	}
	list_b = ft_calloc((argc -1), sizeof(int));
	if (!list_b)
		return (1);
	list_a = make_list((argc -1), argv);
	for(int i = 0; i < argc-1; i++)
		{
        	ft_printf("%d ", list_a[i]);
		}
	ft_printf("\n");
	push_b(&list_a, &list_b, (argc-1));
	for(int i = 0; i < argc-1; i++)
	{
		ft_printf("%d ", list_b[i]);
	}
	ft_printf("\n");
	push_a(&list_a, &list_b, (argc-1));
	for(int i = 0; i < argc-1; i++)
	{
		ft_printf("%d ", list_a[i]);
	}




	return (0);
}

int main(void)
{
    char *argv[] = {"push_swap", "3", "2", "1"};
    int argc = 4;
    main_test(argc, argv);
    return 0;
}