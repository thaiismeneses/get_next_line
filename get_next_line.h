/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:03:50 by thfranco          #+#    #+#             */
/*   Updated: 2023/11/14 18:50:01 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
void	*ft_calloc(size_t n_elements, size_t size);
int		ft_strchr(char *s, int c, int flag);
void	ft_free(char **s);
int		ft_strlen(char *s);
char	*ft_strnjoin(char *s1, char *s2, int position);
char	*ft_strndup(char *input, int position);
char	*ft_update_next_line(char **next_line, int position);
char	*ft_output(char **next_line, int position, int bytes);
#endif
