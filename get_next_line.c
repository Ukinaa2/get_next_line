/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:05:57 by gguedes           #+#    #+#             */
/*   Updated: 2022/05/31 18:15:20 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*g_str;

char	*get_next_line(int fd)
{
	int		bytes_read;
	char	*buffer;
	char	*new_str;
	char	*tmp;

	if (fd < 0 || !BUFFER_SIZE)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!(ft_strchr(g_str, '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!bytes_read || bytes_read == -1)
		{
			free(buffer);
			new_str = g_str;
			g_str = NULL;
			return (new_str);
		}
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(g_str, buffer);
		if (g_str)
			free(g_str);
		g_str = tmp;
	}
	free(buffer);
	new_str = create_new_line(g_str);
	tmp = ft_strdup(ft_strchr(g_str, '\n') + 1);
	free(g_str);
	g_str = tmp;
	return (new_str);
}
