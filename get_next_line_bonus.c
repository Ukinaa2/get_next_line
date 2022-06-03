/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:05:57 by gguedes           #+#    #+#             */
/*   Updated: 2022/06/03 13:39:07 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*create_line(const char *str)
{
	int		i;
	int		j;
	char	*new_str;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	new_str = (char *)malloc(i + 1 * sizeof(char));
	if (!new_str)
		return (NULL);
	j = 0;
	while (j < i)
	{
		new_str[j] = str[j];
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}

char	*find_next_line(char *str)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (str + (i + 1));
		i++;
	}
	return (NULL);
}

char	*check_new_line(int fd, char *str, char *buffer)
{
	int			bytes_read;
	char		*tmp;

	bytes_read = 1;
	while (!(find_next_line(str)) && bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		buffer[bytes_read] = '\0';
		if (!str)
			str = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(str, buffer);
			free(str);
			str = tmp;
		}
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*tmp;
	char		*buffer;
	char		*new_str;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	str[fd] = check_new_line(fd, str[fd], buffer);
	free(buffer);
	new_str = create_line(str[fd]);
	tmp = ft_strdup((find_next_line(str[fd])));
	free(str[fd]);
	str[fd] = tmp;
	return (new_str);
}
