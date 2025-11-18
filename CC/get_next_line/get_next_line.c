/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:06:48 by gvan-box          #+#    #+#             */
/*   Updated: 2025/11/18 18:01:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"
#define BUFFER_SIZE 5

#include <stdio.h>

char	*ft_get_newline(int fd, char *buffer, int char_read, char *temp)
{
	size_t	len;	

	len = 0;
	if (!*buffer)
		return (NULL); 
	if (ft_strchr(buffer, '\n', &len))
	{
		ft_strlcpy(temp, buffer, len + 2);
		return (temp);
	}
	ft_strlcpy(temp, buffer, ft_strlen(buffer) + 1);
	if (!*temp)
		return (NULL);
	return (temp);	
}

char	*ft_read_buffer(int fd, char *buf_read, char **buf_static, char *temp)
{
	int 	char_read;
	size_t	len;
	
	while (ft_strchr(buf_read, '\n', &len) == NULL)
	{
		char_read = read(fd, buf_read, BUFFER_SIZE);
		if (char_read < 0)
			return (NULL);
		else if (char_read == 0)
			return (ft_get_newline(fd, buf_read, char_read, temp));	
		*buf_static = ft_strjoin(*buf_static, buf_read, char_read);
		if (!*buf_static)
			return (NULL);
	}	
	return (ft_get_newline(fd, *buf_static, char_read, temp));
		
}

char	*ft_read_static(char **buf_static, int fd, char *temp, char *buf_read)
{
	size_t len;

	len = 0;
	ft_strchr(*buf_static, '\n', &len);
	ft_memmove(*buf_static, *buf_static + len + 1, BUFFER_SIZE + 1 - len);
	if (!ft_strchr(*buf_static, '\n', &len))
		return (ft_read_buffer(fd, buf_read, buf_static, temp));
	return (ft_get_newline(fd, *buf_static, ft_strlen(*buf_static), temp));
}

char	*ft_error_handling(char	**buf_read, char **buf_static, int fd)
{
	char	*non_error;

	non_error = "no error";	
	if (*buf_read == NULL)
	{
		free(*buf_read);
		free(*buf_static);
		return (NULL);		
	}
	else if (*buf_static != NULL)
	{
		return (NULL);
	}
	else	
		return (non_error);	
}

char	*get_next_line(int fd)
{
	char			*newline;
	char			*buf_read;
	char			*temp;
	static char		*buf_static = NULL;	

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	buf_read = malloc(BUFFER_SIZE + 1);
	if (!buf_read)
		return (NULL);	
	if (buf_static != NULL)
	{		
		newline = ft_read_static(&buf_static, fd, temp, buf_read);
		if (!newline)
			return(ft_error_handling(&buf_read, &buf_static, fd));
		return (newline);
	}
	newline = ft_read_buffer(fd, buf_read, &buf_static, temp);
	if (!newline)
		return(ft_error_handling(&buf_read, &buf_static, fd));
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
	while (str != NULL)
	{
		//printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	close (fd);

}