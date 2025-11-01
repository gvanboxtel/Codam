/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:16:15 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/21 14:39:52 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_lstsize(t_list *lst)
{
	size_t	counter;

	counter = 0;
	while (lst)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
}

// int main(void)
// {
// 	t_list	*head;
// 	int	lstlength;
// 	head = ft_lstnew(ft_strdup("Hallo"));
// 	ft_lstadd_back(&head, ft_lstnew(ft_strdup("Hoe")));
// 	ft_lstadd_back(&head, ft_lstnew(ft_strdup("werkt dit?")));	
// 	lstlength = ft_lstsize(head);
// 	printf("%d", lstlength);
// 	return (0); 
// }