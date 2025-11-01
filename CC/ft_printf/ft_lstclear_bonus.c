/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:30:34 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/23 09:43:25 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

// void	ft_del(void *arg)
// {
// 	free(arg);
// }

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*nextnode;

	if (*lst == NULL)
		return ;
	current = *lst;
	nextnode = current->next;
	while (nextnode)
	{
		del(current->content);
		free(current);
		current = nextnode;
		nextnode = current->next;
	}
	del(current->content);
	free(current);
	*lst = NULL;
}

// int main(void)
// {
// 	t_list *head;
// 	t_list	*temp;
// 	char	*str;
// 	str = ft_strdup("Hallo, ");		
// 	head = ft_lstnew(str);
// 	ft_lstadd_back(&head, ft_lstnew(ft_strdup("Geweldig")));
// 	ft_lstadd_back(&head, ft_lstnew(ft_strdup("Ik snap hier niks van")));	
// 	temp = head;
// 	while(temp)
// 	{
// 		printf("%s -> ", (char *)temp->content);
// 		temp = temp->next;
// 	}
// 	t_list *head2 = NULL;
// 	printf("END\n\n");
// 	ft_lstclear(&head, ft_del);
// 	ft_lstclear(&head2, ft_del);
// 	printf("head value: %p\n", head);
// }