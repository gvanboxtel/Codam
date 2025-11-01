/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:27:24 by gvan-box          #+#    #+#             */
/*   Updated: 2025/10/21 11:14:40 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

// void	ft_del(void *content)
// {
// 	free(content);		
// }

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}

// int main(void)
// {
// 	t_list *Node;
// 	t_list	*temp;
// 	char	*str;
// 	str = ft_strdup("Hallo");	
// 	Node = ft_lstnew(str);
// 	temp = Node;
// 	ft_lstdelone(temp, ft_del);	
// }