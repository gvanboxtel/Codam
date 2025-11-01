/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:55:02 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/22 19:24:05 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// int main(void)
// {
// 	t_list	*head;
// 	t_list	new;
// 	t_list	*temp;
// 	int	data;
// 	int newData;
// 	t_list	*lastNode;	
// 	newData = 10;
// 	new.content = &newData;
// 	head = ft_lstnew(&data);
// 	//ft_lstadd_front(&head, &new);
// 	temp = head;
// 	lastNode = ft_lstlast(head);
// 	printf("%d\n", *(int *)lastNode->content);
// 	return (0); 
// }