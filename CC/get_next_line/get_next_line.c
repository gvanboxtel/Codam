/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-box <gvan-box@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:06:48 by gvan-box          #+#    #+#             */
/*   Updated: 2025/11/03 13:17:28 by gvan-box         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"
#define BUFFER_SIZE 50

#include <stdio.h>

static char	*ft_get_buffer(int fd)
{
	char	*buffer;
	int		char_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	char_read = read(fd, buffer, BUFFER_SIZE);
	if (char_read < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (char_read == 0)
	{
		//printf("check");
		buffer[char_read] = '\0';
		return (buffer);
	}

	buffer[char_read] = '\0';
	return (buffer);
}

static t_list	*ft_get_list(t_list *lst, int fd, size_t *len)
{
	char	*buffer;
	size_t	i;

	i = 0;
	*len = 0;
	buffer = ft_get_buffer(fd);
	while (buffer[i] != '\n' && *buffer)
	{
		i++;
		(*len)++;
		if (buffer[i] == '\0')
		{
			ft_lstadd_back(&lst, ft_lstnew(buffer));
			buffer = ft_get_buffer(fd);
			i = 0;
		}
	}
	ft_lstadd_back(&lst, ft_lstnew(buffer));
	return (lst);
}

static char	*ft_get_newline(t_list *lst, size_t *len)
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
		//printf("Content: %s\n", content);
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

static t_list	*ft_clean_list(t_list *lst, size_t *len)
{
	char	*buffer;
	char	*str;
	size_t	size;
	char	*start;

	size = 0;
	while (lst->next)
	{
		if (ft_strlen(lst->content) < *len)
			*len -= ft_strlen(lst->content);
		else
			(*len)++;
		lst = lst->next;
	}
	start = lst->content + (((*len)--) + 1);
	str = (char *)lst->content;
	while (str[(*len)++])
		size++;
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

	len = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lst = ft_get_list(lst, fd, &len);
	if (lst == NULL)
		return (NULL);
	newline = ft_get_newline(lst, &len);
	lst = ft_clean_list(lst, &len);
	return (newline);
}

#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd;
	char *str;
	char *buffer;

	fd = open("sample.txt", O_RDONLY);
	str = get_next_line(fd);
	//printf("%s", str);
	free(str);
	str = get_next_line(fd);
	//printf("%s", str);
	free(str);
	str = get_next_line(fd);
	//printf("%s", str);
	free(str);
	// str = get_next_line(fd);
	// printf("%s\n", str);

}