/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:08:44 by gvan-box          #+#    #+#             */
/*   Updated: 2025/12/12 11:40:47 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// top of b and put it on a
void push_a(stack **list_a, stack **list_b)
{
	stack *second;

	if (!(*list_b))
		return ;
	second = (*list_b)->next;
	if (second)
		second->prev = NULL;
	if (!(*list_a))
	{
		(*list_a) = (*list_b);
		(*list_b)->next = NULL;
		(*list_b)->prev = NULL;
		(*list_b) = second;
		return ;
	}
	(*list_a)->prev = (*list_b);
	(*list_b)->next = (*list_a);
	(*list_a) = (*list_b);
	if ((*list_b)->next != NULL)
	{
		(*list_b)->next->prev = NULL;
	}
	(*list_b) = second;
}

void push_b(stack **list_a, stack **list_b)
{
	stack *second;

	if (!(*list_a))
		return ;
	second = (*list_a)->next;
	if (second)
		second->prev = NULL;
	if (!(*list_b))
	{
		(*list_b) = (*list_a);
		(*list_a)->next = NULL;
		(*list_a)->prev = NULL;
		(*list_a) = second;
		return ;
	}
	(*list_b)->prev = (*list_a);
	(*list_a)->next = (*list_b);
	(*list_b) = (*list_a);
	if ((*list_a)->next != NULL)
	{
		(*list_a)->next->prev = NULL;
	}
	(*list_a) = second;
}
