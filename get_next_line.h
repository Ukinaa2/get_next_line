/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:10:16 by gguedes           #+#    #+#             */
/*   Updated: 2022/05/28 15:51:16 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 42
# include <stdlib.h>
# include <unistd.h>

static char	*g_str;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s, char *tmp);
char	*create_line(char *s);
size_t	ft_strlen(char *s);
int		new_line(char *s);

#endif
