/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:27:41 by thfranco          #+#    #+#             */
/*   Updated: 2023/11/26 20:33:41 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

void	ft_free(char **s);
int		ft_strlen(char *s);
int		ft_strchr(char *s, int c, int flag);
char	*ft_strnjoin(char *s1, char *s2, int position);
char	*ft_strndup(char *input, int position);
void	*ft_calloc(size_t n_elements, size_t size);
char	*ft_update_next_line(char **next_line, int position);
char	*ft_output(char **next_line, int position, int bytes);
char	*get_next_line(int fd);
#endif
