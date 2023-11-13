/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:49:51 by thfranco          #+#    #+#             */
/*   Updated: 2023/11/13 19:14:16 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **s)
{
	free(*s);
	*s = NULL;
}

/*
** if flag == 0, will return -1 if found NULL;
** if flag == 1, will return -5 if found NULL;
*/

int	*ft_strchr(char *s, int c, int flag)
{
	int	i;

	i = 0;
	if (flag == 1 || !s)
		return (-5);
	while (s && s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(char *s)
{
	int	i;
	
	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}


char	*ft_strnjoin(char *s1, char *s2, int position)
{
	char	*output;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	output = malloc(ft_strlen(s1) + position + 1);
	if (!output)
		return (NULL);
	while (s1[i])
	{
		output[i] = s1[i];
		i++;
	}
	while (s2[j] && j <= position)
		output[i++] = s2[j++];
	output[i] = '\0';
	if (s1)
		ft_free(output);
	return (output);
}
