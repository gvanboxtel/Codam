/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:16:49 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/20 12:16:49 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * @brief makes a new linked list
 * 
 * @param content content of that first node
 * @return t_list* returns the linked list
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
// #include <stdio.h>
// int main(void)
// {
// 	int	content;
// 	t_list	*lst;
// 	t_list	*temp;	
// 	content = 50;
// 	lst = ft_lstnew(&content);
// 	printf("Linked List: ");
// 	temp = lst;
// 	while(temp)
// 	{
// 		printf("%d\n", *(int *)temp->content);
// 		temp= temp->next;
// 	}
// 	return (0);
// }