/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:57:50 by marvin            #+#    #+#             */
/*   Updated: 2025/12/09 10:57:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

stack	*ft_lstnew_double(int content)
{
	stack	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

stack	*ft_lstlast_double(stack *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_double(stack **lst, stack *new)
{
	stack	*temp;

	if (*lst == NULL)
	{
		*lst = new;
		new->prev = NULL;
		return ;
	}
	else
	{
		temp = ft_lstlast_double(*lst);
		temp->next = new;
		new->prev = temp;
	}
}

void	ft_lstadd_front_double(stack **lst, stack *new)
{
	if (*lst == NULL)
	{
		new->prev = NULL;
		*lst = new;
		return ;
	}
	else
	{
		new->next = *lst;
		new->prev = NULL;
		(*lst)->prev = new;
		*lst = new;
	}
}

