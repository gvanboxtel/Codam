/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:20:55 by marvin            #+#    #+#             */
/*   Updated: 2025/11/23 15:20:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"
#define BUFFER_SIZE 5
#include <stdio.h>

char	*ft_join(char *old_line, char *buffer)
{

	char	*new_line;
	new_line = ft_strjoin(old_line, buffer);
	return (free(old_line), new_line);
}

char	*ft_get_remainder(char **remainder, char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i] != '\n')
		i++;
	*remainder = calloc(ft_strlen(buffer + i + 1) + 1, sizeof(char));
	if (!*remainder)
		return (NULL);
	*remainder = ft_memmove(*remainder, buffer + i + 1, ft_strlen(buffer + i + 1));
	return (*remainder);
}

char	*ft_get_newline(char *new_line)
{
	size_t	i;

	i = 0;
	while (new_line[i] != '\n')
		i++;
	new_line[i + 1] = '\0';
	return (new_line);
}

char	*ft_read(int fd, char	*new_line, char **remainder)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;

	buffer[0] = '\0';
	while (!new_line || ft_strchr(new_line, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0 )			
			return (free(*remainder), *remainder = NULL, NULL);		
		else if (bytes_read == 0)
		{
			if (!new_line)
				return (NULL);
			buffer[bytes_read] = '\0';
			new_line = ft_join(new_line, buffer);			
			return (free(*remainder), *remainder = NULL, new_line);
		}
		buffer[bytes_read] = '\0';
		new_line = ft_join(new_line, buffer);
	}
	if (!*buffer)
		ft_strlcpy(buffer, new_line, ft_strlen(new_line) + 1);
	*remainder = ft_get_remainder(remainder, buffer);
	return (ft_get_newline(new_line));	
}


char	*get_next_line(int fd)
{
	static char	*remainder[1024];
	char		*new_line;

	new_line = NULL;
	if (remainder[fd])
	{
		new_line = ft_join(new_line, remainder[fd]);
		free(remainder[fd]);
		remainder[fd] = NULL;
	}
	new_line = ft_read(fd, new_line, &remainder[fd]);
	return (new_line);
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
		// printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	close (fd);

}