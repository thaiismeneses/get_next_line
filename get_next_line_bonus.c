/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:56:55 by thfranco          #+#    #+#             */
/*   Updated: 2023/11/28 12:15:19 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t n_elements, size_t size)
{
	char			*allocated_memory;
	size_t			total;
	unsigned int	i;

	i = 0;
	total = n_elements * size;
	allocated_memory = (char *)malloc(total);
	if (!allocated_memory)
		return (0);
	while (i < total)
	{
		allocated_memory[i] = 0;
		i++;
	}
	return (allocated_memory);
}

char	*ft_update_next_line(char **next_line, int position)
{
	char	*temp;
	int		length;

	length = ft_strlen(*next_line) - position;
	temp = ft_strndup (*next_line + position, length);
	ft_free(&*next_line);
	*next_line = temp;
	return (*next_line);
}

char	*ft_output(char **next_line, int position, int bytes)
{
	char	*line;

	if (((bytes == 0 || bytes == -1) && !*next_line) || position == -42)
	{
		if (*next_line)
			return (*next_line);
		return (NULL);
	}
	line = NULL;
	if (position == -1)
		position = ft_strlen(*next_line);
	else
		position++;
	line = ft_strndup(*next_line, position);
	if (position == ft_strlen(*next_line))
		ft_free(&*next_line);
	else
		*next_line = ft_update_next_line(&*next_line, position);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*next_line[1024];
	char		*buff;
	int			position;
	int			bytes;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = NULL;
	bytes = 0;
	position = ft_strchr(next_line[fd], '\n', 0);
	while (position == -1 && position != -42)
	{
		buff = ft_calloc(BUFFER_SIZE + 1, 1);
		if (buff == NULL)
			return (NULL);
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == 0 || bytes == -1)
			break ;
		next_line[fd] = ft_strnjoin(next_line[fd], buff, bytes);
		position = ft_strchr(next_line[fd], '\n', 1);
		ft_free(&buff);
	}
	ft_free(&buff);
	return (ft_output(&next_line[fd], position, bytes));
}
