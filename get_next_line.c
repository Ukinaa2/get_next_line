/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:05:57 by gguedes           #+#    #+#             */
/*   Updated: 2022/05/31 13:49:35 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*g_str;

char	*get_next_line(int fd)
{
	int		bytes_read;
	char	*buffer;
	char	*new_str;

	if (fd < 0 || !BUFFER_SIZE)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!(ft_strchr(g_str, '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		g_str = ft_strjoin(g_str, buffer);
	}
	free(buffer);
	new_str = create_new_line(g_str);
	g_str = ft_strdup(ft_strchr(g_str, '\n') + 1);
	if (!(ft_strchr(new_str, '\n')))
		new_str = ft_strjoin(new_str, "\n");
	return (new_str);
}
