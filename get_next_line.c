/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:05:57 by gguedes           #+#    #+#             */
/*   Updated: 2022/05/28 15:52:55 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*tmp;

	tmp = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!tmp)
		return (0);
	if (g_str)
	{
		printf("str exists: \"%s\"\n", g_str);
		if (new_line(g_str))
		{
			printf("str has \\n\n");
			return (create_line(g_str));
		}
	}
	while (read(fd, tmp, BUFFER_SIZE))
	{
		printf("tmp: \"%s\"\n", tmp);
		g_str = ft_strjoin(g_str, tmp);
		printf("str: \"%s\"\n", g_str);
		if (new_line(g_str))
		{
			printf("str has \\n\n");
			return (create_line(g_str));
		}
		free(tmp);
	}
	return (0);
}
