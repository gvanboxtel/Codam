/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:06:48 by gvan-box          #+#    #+#             */
/*   Updated: 2025/11/01 15:16:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"
#define BUFFER_SIZE 10

char	*ft_buffer(int fd)
{
	char	*buffer;
	int		char_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	char_read = read(fd, buffer, BUFFER_SIZE);
	if (!char_read)
	{
		free(buffer);
		return (NULL);
	}
	buffer[char_read] = '\0';
	return (buffer);
}

t_list	*ft_get_list(t_list *lst, int fd, size_t *len)
{
	char	*buffer;
	size_t	i;

	i = 0;
	*len = 0;
	buffer = ft_buffer(fd);
	while (buffer[i] != '\n')
	{
		i++;
		(*len)++;
		if (buffer[i] == '\0')
		{
			ft_lstadd_back(&lst, ft_lstnew(buffer));
			buffer = ft_buffer(fd);
			i = 0;
		}
	}
	ft_lstadd_back(&lst, ft_lstnew(buffer));
	return (lst);
}

char	*ft_get_newline(t_list *lst, size_t *len)
{
	char	*content;
	char	*str;
	char	*start;

	str = malloc(*len + 1);
	if (!str)
		return (NULL);
	start = str;
	while (lst)
	{
		content = lst->content;
		while (*content != '\n' && *content)
		{
			*str++ = *content++;
			if (*content == '\n')
			{
				*str++ = *content;
				*str = '\0';
				return (start);
			}
		}
		lst = lst->next;
	}
	return (start);
}

t_list	*ft_clean_list(t_list *lst, size_t *len)
{
	char	*buffer;
	char	*str;
	size_t	offset;
	size_t	size;
	char	*start;

	size = 0;
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		if (ft_strlen(lst->content) < *len)
		{
			*len -= ft_strlen(lst->content);
			lst = lst->next;
		}
		else
		{
			offset = *len + 1;
			break ;
		}
	}
	start = lst->content + offset;
	str = (char *)lst->content;
	while (str[offset])
	{
		size++;
		offset++;
	}
	buffer = malloc(size + 1);
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, start, (size + 1));
	ft_lstclear(&lst, free);
	lst = ft_lstnew(buffer);
	return (lst);
}

char	*get_next_line(int fd)
{
	size_t			len;
	char			*newline;
	static t_list	*lst = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, newline, 0) < 0)
		return (NULL);
	lst = ft_get_list(lst, fd, &len);
	newline = ft_get_newline(lst, &len);
	lst = ft_clean_list(lst, &len);
	return (newline);
}

// #include <fcntl.h>
// #include <stdio.h>

// int main(void)
// {
// 	int fd;
// 	char *str;
// 	char *buffer;

// 	fd = open("sample.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	printf("%s\n", str);
// 	str = get_next_line(fd);
// 	printf("%s\n", str);
// 	// str = get_next_line(fd);
// 	// printf("%s\n", str);

// }