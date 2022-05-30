/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:05:57 by gguedes           #+#    #+#             */
/*   Updated: 2022/05/30 12:43:52 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*g_str;

char	*get_next_line(int fd)
{
	char	*line;
	char	*tmp;
	int		count_read;

	tmp = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!tmp)
		return (NULL);
	count_read = 1;
	while (!(check_new_line(g_str)))
	{
		count_read = read(fd, tmp, BUFFER_SIZE);
		tmp[count_read] = '\0';
		g_str = ft_strjoin(g_str, tmp);
		if (!count_read && !(check_new_line(g_str)))
			g_str = ft_strjoin(g_str, "\n");
	}
	free(tmp);
	line = create_line(g_str);
	g_str += check_new_line(g_str);
	if (line[0] == '\n' && !count_read)
		return (NULL);
	return (line);
}
