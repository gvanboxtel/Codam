/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:30:30 by marvin            #+#    #+#             */
/*   Updated: 2025/12/10 17:30:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// 8 4 3
// 4 8 3
// 4 3 8
int *sort_set_index(stack *list_a)
{
	stack *sorted_index;
	int list_size;
	int largest;
	int next;

	list_size = ft_lstsize(list_a);
	sorted_index = list_a;
	largest = list_a->content;
	next = list_a->next->content;
	while (list_a->next != NULL && next && next < largest)
	{
		if (largest > next)
		{
			swap_a(&list_a);
			list_a->next;
			largest = list_a->content;
		}
	}
	
	
}