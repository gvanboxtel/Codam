/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:48:46 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/22 19:23:59 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_foo(void *foo)
// {
// 	printf("Content: %s\n", (char *)foo);
// }

/**
 * @brief iterates through list and applies function to its content
 * 
 * @param lst the linked list
 * @param f the function
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// int main(void)
// {
// 	t_list	*node1;
// 	node1 = ft_lstnew(ft_strdup("Hello"));
// 	ft_lstadd_back(&node1, ft_lstnew(ft_strdup("Bonjour")));
// 	ft_lstadd_back(&node1, ft_lstnew(ft_strdup("Test1")));
// 	ft_lstiter(node1, ft_foo);
// 	return (0);
// }