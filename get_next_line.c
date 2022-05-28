/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:05:57 by gguedes           #+#    #+#             */
/*   Updated: 2022/05/28 14:27:56 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*str;

size_t	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	new_line(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*create_line(char *s)
{
	int		i;
	char	*new_str;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	new_str = (char *)malloc(i + 1 * sizeof(char));
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\n';
	i++;
	str = str + i;
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strjoin(char *s, char *tmp)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = (char *)malloc(ft_strlen(s) + ft_strlen(tmp) + 1 * sizeof(char));
	if (s)
	{
		while (*s)
		{
			new_str[i] = *s;
			s++;
			i++;
		}
	}
	while (*tmp)
	{
		new_str[i] = *tmp;
		tmp++;
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*get_next_line(int fd)
{
	char	*tmp;

	tmp = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!tmp)
		return (0);
	if (str)
	{
		if (new_line(str))
		{
			return (create_line(str));
		}
	}
	while (read(fd, tmp, BUFFER_SIZE))
	{
		str = ft_strjoin(str, tmp);
		if (new_line(str))
		{
			return (create_line(str));
		}
	}
	return (0);
}

//verifica se a string lida possui um \n
//se possuir, printa a string e salva o resto
//se não, concatena as strings
//repete o processo
