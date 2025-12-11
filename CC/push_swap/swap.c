/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:08:38 by gvan-box          #+#    #+#             */
/*   Updated: 2025/12/09 11:56:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(stack **list_a)
{
    stack *first;
    stack *second;
    stack *third;
	
    if (!list_a || !*list_a || !(*list_a)->next)
        return;
    first = *list_a;
    second = first->next;
    third = second->next;    
    second->prev = NULL;
    second->next = first;
    first->prev = second;
    first->next = third;
    if (third)
        third->prev = first;    
    *list_a = second;
}

void swap_b(stack **list_b)
{
    stack *first;
    stack *second;
    stack *third;
	
    if (!list_b || !*list_b || !(*list_b)->next)
        return;
    first = *list_b;
    second = first->next;
    third = second->next;    
    second->prev = NULL;
    second->next = first;
    first->prev = second;
    first->next = third;
    if (third)
        third->prev = first;    
    *list_b = second;
}

void ss(stack **list_a, stack **list_b)
{
	swap_a(list_a);
	swap_b(list_b);
}