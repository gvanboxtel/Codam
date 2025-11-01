/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:15:49 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/22 19:12:56 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

// void	ft_del(void *content)
// {
// 	free(content);	
// }

// void	*ft_strtoupper(void *arg)
// {
// 	size_t 	i = 0;
// 	char *str = arg;

// 	char *newString = malloc(sizeof(char) * (ft_strlen(str) + 1));
// 	if (!newString) {
// 		return (NULL);
// 	}

// 	while (str[i]) {
// 		newString[i] = ft_toupper(str[i]);
// 		i++;
// 	}
// 	return (newString);
// }

// void *returnNull(void *arg) {
// 	return (NULL);
// }

/**
 * @brief applies function to lst and del if new_node is NULL
 * 
 * @param lst linked list
 * @param f function
 * @param del del function
 * @return t_list* returns new_lst with applied function
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_lst;
	void	*new_content;

	new_lst = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (new_node == NULL)
		{
			ft_lstclear(&new_lst, del);
			del(new_content);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

// int main(void)
// {
// 	t_list *head;
// 	char	*str;
// 	t_list *newlst;
// 	str = ft_strdup("Hallo, ");		
// 	head = ft_lstnew(str);
// 	ft_lstadd_back(&head, ft_lstnew(ft_strdup("Geweldig")));
// 	ft_lstadd_back(&head, ft_lstnew(ft_strdup("Ik snap hier niks van")));	
// 	newlst = ft_lstmap(head, returnNull, ft_del);
// 	while(newlst)
// 	{
// 		printf("%s -> ", (char *)newlst->content);
// 		newlst = newlst->next;
// 	}
// 	printf("\n\n\nold list:\n");
// 	t_list *temp = head;
// 	while(temp)
// 	{
// 		printf("%s -> ", (char *)temp->content);
// 		temp = temp->next;
// 	}
// }