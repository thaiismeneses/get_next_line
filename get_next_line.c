/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:49:21 by thfranco          #+#    #+#             */
/*   Updated: 2023/11/13 19:14:12 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t n_elements, size_t size)
{
	char			*allocated_memory;
	size_t			total;
	unsigned int	i;

	i = 0;
	total = n_elements * size;
	allocated_memory = malloc(total);
	if (!allocated_memory)
		return (0);
	while (i < total)
	{
		allocated_memory[i] = 0;
		i++;
	}
	return (allocated_memory);
}

char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*buff;
	int	position;
	int	bytes;

	if (BUFFER_SIZE <= 0 || fd < 0 )
		return (NULL);
	buff = NULL;
	position = ft_strchr(next_line, '\n', 0);
	while (position == -1 && position == -5)
	{
		buff = ft_calloc(BUFFER_SIZE + 1, 1);
		if (buff == NULL)
			return (NULL);
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == 0 || bytes == -1)
			break ;
		next_line = ft_strnjoin(next_line, buff, bytes);
	}
}
