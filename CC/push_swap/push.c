/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:08:44 by gvan-box          #+#    #+#             */
/*   Updated: 2025/12/10 08:43:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// top of b and put it on a
void push_a(stack **list_a, stack **list_b, int counter)
{
	stack *top_b;
	stack *top_a;

	if (!(*list_b))
		return ;
	top_b = *list_b;
	top_a = (*list_a);
	top_a->prev = top_b;
	(*list_a) = top_b;
	if (top_b->next != NULL)
	{
		top_b->next->prev = NULL;	
	}
	(*list_b) = top_b->next;	
}

void push_b(int **list_a, int **list_b, int counter)
{
	stack *top_b;
	stack *top_a;

	if (!(*list_a))
		return ;
	top_b = *list_b;
	top_a = (*list_a);
	top_b->prev = top_a;
	(*list_b) = top_a;
	if (top_a->next != NULL)
	{
		top_a->next->prev = NULL;	
	}
	(*list_a) = top_a->next;	
}
