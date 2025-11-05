/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:07:06 by gvan-box          #+#    #+#             */
/*   Updated: 2025/11/03 13:19:04 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "get_next_line.h"

t_list	*ft_lstnew(void *content, size_t n)
{
	t_list	*node;
	char	*str;
	char	*buffer;

	str = (char *)content;
	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	buffer = malloc(n);
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, str, n);
	node->content = buffer;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

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

size_t	ft_strlen(const char *s)
{
	const char	*iterator;

	iterator = s;
	while (*iterator)
		iterator++;
	return (iterator - s);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (size > 0)
	{
		size = size -1;
		while (size-- && *s)
			*d++ = *s++;
		*d = '\0';
	}
	return (ft_strlen(src));
}
