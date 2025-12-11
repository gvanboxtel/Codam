/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:08:48 by gvan-box          #+#    #+#             */
/*   Updated: 2025/12/10 08:41:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// shift up all elements
void rotate_a(stack **list_a)
{
	stack *first;
	stack *last;

	first = (*list_a);
	last = ft_lstlast_double(*list_a);
	last->next = first->next;
	first->next = NULL;
	first->prev = last->prev;
	// 321 -> 213
	(*list_a) = last;
	
}

void rotate_b(stack **list_b)
{
	stack *first;
	stack *last;

	first = (*list_b);
	last = ft_lstlast_double(*list_b);
	last->next = first->next;
	first->next = NULL;
	first->prev = last->prev;
	// 321 -> 213
	(*list_b) = last;
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
	// 321 -> 132

	first = (*list_a);
	last = ft_lstlast_double(*list_a);
	first->prev = last;
	last->next = first;
	(*list_a) = last;
}

void	reverse_rotate_b(stack **list_b)
{
	stack *first;
	stack *last;
	// 321 -> 132

	first = (*list_b);
	last = ft_lstlast_double(*list_b);
	first->prev = last;
	last->next = first;
	(*list_b) = last;
}

void rrr(stack **list_a, stack **list_b)
{
	reverse_rotate_a(list_a);
	reverse_rotate_b(list_b);
}