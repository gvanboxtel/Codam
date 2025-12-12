/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:08:48 by gvan-box          #+#    #+#             */
/*   Updated: 2025/12/12 15:52:41 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// shift up all elements
void rotate_a(stack **list_a)
{
	stack *first;
	stack *second;
	stack *last;

	if ((*list_a)->next == NULL)
		return ;
	first = (*list_a);
	second = first->next;
	last = ft_lstlast_double(*list_a);
	second->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	(*list_a) = second;
}

void rotate_b(stack **list_b)
{
	stack *first;
	stack *second;
	stack *last;

	if ((*list_b)->next == NULL)
		return ;
	first = (*list_b);
	second = first->next;
	last = ft_lstlast_double(*list_b);
	second->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	(*list_b) = second;
}

void	rr(stack **list_a, stack **list_b)
{
	rotate_a(list_a);
	rotate_b(list_b);
}

// shift down
void	reverse_rotate_a(stack **list_a)
{
	stack *first;
	stack *last;
	stack *second_last;
	// 321 -> 132
	if (!list_a || !(*list_a) || !(*list_a)->next)
    	return;
	first = (*list_a);
	last = ft_lstlast_double(*list_a);
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	first->prev = last;
	last->next = first;
	(*list_a) = last;
}

void	reverse_rotate_b(stack **list_b)
{
	stack *first;
	stack *last;
	stack *second_last;
	// 321 -> 132
	if (!list_b || !(*list_b) || !(*list_b)->next)
    	return;
	first = (*list_b);
	last = ft_lstlast_double(*list_b);
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	first->prev = last;
	last->next = first;
	(*list_b) = last;
}

void rrr(stack **list_a, stack **list_b)
{
	reverse_rotate_a(list_a);
	reverse_rotate_b(list_b);
}