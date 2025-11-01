/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:07:09 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/22 18:57:56 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
	}
}

// int main(void)
// {
// 	t_list	*head;
// 	t_list	new;
// 	t_list	*temp;
// 	int	data;
// 	int newData;
// 	data = 50;
// 	newData = 10;
// 	new.content = &newData;
// 	head = ft_lstnew(&data);
// 	ft_lstadd_back(&head, &new);
// 	//ft_lstadd_front(&head, &new);
// 	temp = head;
// 	while(temp != NULL)
// 	{
// 		printf("%d -> ", *(int *)temp->content);
// 		temp = temp->next;
// 		if (temp == NULL)
// 			printf("NULL");
// 	}
// 	return (0); 
// }