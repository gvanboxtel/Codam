/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:08:27 by gvan-box          #+#    #+#             */
/*   Updated: 2025/12/09 12:02:12 by marvin           ###   ########.fr       */
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

int main_test(int argc, char **argv)
{
	int i;
	stack *list_a = NULL;
	stack *list_b = NULL;

	i = 1;
	if (argc > 1)
	{
		while (i < argc && argv[i][0])
		{
			if (ft_isdigit(argv[i][0]))
				ft_lstadd_back_double(&list_a, ft_lstnew_double(ft_atoi(argv[i])));
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
	swap_a(&list_a);
	for(int i = 0; i < argc-1; i++)
		{
        	printf("%d ", list_a->content);
			list_a = list_a->next;
		}
	printf("\n");
	
	// push_b(&list_a, &list_b, (argc-1));
	// for(int i = 0; i < argc-1; i++)
	// {
	// 	ft_printf("%d ", list_b[i]);
	// }
	// ft_printf("\n");
	// push_a(&list_a, &list_b, (argc-1));
	// for(int i = 0; i < argc-1; i++)
	// {
	// 	ft_printf("%d ", list_a[i]);
	// }




	return (0);
}

int main(void)
{
    char *argv[] = {"push_swap", "3", "2", "1"};
    int argc = 4;
    main_test(argc, argv);
    return 0;
}