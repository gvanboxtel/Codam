/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 10:30:42 by gvan-box          #+#    #+#             */
/*   Updated: 2025/12/12 16:55:38 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void print_list(stack *list)
{
	int i;
	stack *head;

	head = list;
	i = ft_lstsize_double(list);
	printf("List: ");
	while (i > 0)
	{
		printf("%d ", (list)->content);
		(list) = list->next;
		i--;
	}
	printf("\n");
	printf("rank: ");
	list = head;
	i = ft_lstsize_double(list);
	while (i > 0)
	{
		printf("%d ", (list)->rank);
		(list) = list->next;
		i--;
	}
	printf("\n");
}
void sort_3(stack **list_a)
{
	int data1;
	int data2;
	int data3;

	data1 = (*list_a)->content;
	data2 = (*list_a)->next->content;
	data3 = (*list_a)->next->next->content;
	if (data1 < data2 && data2 < data3)
		return;
	else if (data2 < data1 && data1 < data3)
		swap_a(list_a);
	else if (data2 < data3 && data3 < data1)
		reverse_rotate_a(list_a);
	else if (data3 < data2 && data2 < data1)
	{
		swap_a(list_a);
		reverse_rotate_a(list_a);
	}
	else if (data1 < data3 && data3 < data2)
	{
		reverse_rotate_a(list_a);
		swap_a(list_a);
	}
	else
		rotate_a(list_a);
}

int find_max_index(stack *list_b)
{
	int max;
	int i;
	int index;
	int temp;

	i = 0;
	index = 0;
	max = (list_b)->content;
	while ((list_b)->next)
	{
		temp = (list_b)->content;
		if (temp > max)
		{
			index = i;
			max = temp;
		}
		(list_b) = (list_b)->next;
		i++;
	}
	return (index);
}

void rotate_to_top(stack **list, int index)
{
	int reverse_steps;
	int list_size;

	list_size = ft_lstsize_double((*list));
	if (index <= (list_size / 2))
	{
		while (index != 0)
		{
			rotate_a(list);
			index--;
		}
	}
	else
	{
		reverse_steps = (list_size  - index);
		while (reverse_steps != 0)
		{
			reverse_rotate_a(list);
			reverse_steps--;
		}
	}
}

bool is_sorted(int *arr, size_t size)
{
	size_t i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (false);
		i++;
	}
	return (true);
}

int *stack_to_array(stack *list_a, int size)
{
	int *arr;
	int i;

	i = 0;
	arr = malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	while (list_a)
	{
		arr[i] = list_a->content;
		list_a = list_a->next;
		i++;
	}
	return (arr);
}

int *bubble_sort(int *arr, int size)
{
	int i;
	int temp;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
		}
		i++;
	}
	if (is_sorted(arr, size) == false)
		bubble_sort(arr, size);
	return (arr);
}
stack *maps_to_rank(stack *list)
{
	int *arr;
	int size;
	stack *head;
	int i;

	i = 0;
	size = ft_lstsize_double(list);
	arr = stack_to_array(list, size);
	arr = bubble_sort(arr, size);
	head = list;
	while (list)
	{
		while (i < size)
		{
			if (arr[i] == list->content)
			{
				list->rank = i;
				break ;
			}
			i++;
		}
		i = 0;
		list = list->next;
	}
	free (arr);
	list = head;
	return (list);
}

void	reinsertion(stack **list_a, stack **list_b)
{
	stack *head;
	int size;
	int index;

	head = *list_b;
	size = ft_lstsize_double(*list_b);
	*list_b = head;
	while (*list_b)
	{
		index = find_max_index(*list_b);
		rotate_to_top(list_b, index);
		push_a(list_a, list_b);
	}
}

void	push_chunk(stack **list_a, stack **list_b, int chnk_start, int chnk_mid, int chnk_end)
{
	stack *head;
	int count;
	int rank;

	count = 0;
	head = (*list_a);
	while (*list_a)
	{
		if ((*list_a)->rank >= chnk_start && (*list_a)->rank <= chnk_end)
			count++;
		(*list_a) = (*list_a)->next;
	}
	(*list_a) = head;
	while (count > 0 && (ft_lstsize_double(*list_a) <= 3))
	{
		rank = (*list_a)->rank;
		if (rank >= chnk_start && rank <= chnk_end)
		{
			push_b(list_a, list_b);
			if (rank <= chnk_mid)
				rotate_b(list_b);
			count--;
		}
		else
			rotate_a(list_a);
	}
}

int main_test(int argc, char **argv)
{
	int i;
	int j;
	int chunk_start;
	int chunk_mid;
	int chunk_end;
	stack *list_a = NULL;
	stack *list_b = NULL;

	i = 0;
	j = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (ft_isdigit(argv[1][i]))
			{
				j = i;
				while (argv[1][j] && ft_isdigit(argv[1][j]))
					j++;
				ft_lstadd_back_double(&list_a, ft_lstnew_double(ft_atoi(&argv[1][i])));
				i = j;
			}
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
	chunk_start = 0;
	chunk_mid = 10;
	chunk_end = 20;
	list_a = maps_to_rank(list_a);
	while (ft_lstsize_double(list_a) > 3)
	{
		push_chunk(&list_a, &list_b, chunk_start, chunk_mid, chunk_end);
		chunk_start += 10;
		chunk_mid += 10;
		chunk_end += 10;
	}
	list_a = maps_to_rank(list_a);
	list_b = maps_to_rank(list_b);
	print_list(list_a);
	print_list(list_b);
	// sort_upto_20(&list_a, &list_b);
	// printf("b: ");
	// for(int i = ft_lstsize_double(list_b); i > 0; i--)
	// 	{
    //     	printf("%d ", list_b->content);
	// 		list_b = list_b->next;
	// 	}

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
    // char *argv[] = {"push_swap", "18", "20", "11", "30", "23", "10", "33", "25", "1", "36", "29", "14", "35", "24", "17", "32", "21", "16", "3", "2"};
	char *argv[] = {"push_swap", "18 20 11 35"};

	int argc = 2;
    main_test(argc, argv);
    return 0;
}