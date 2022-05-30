/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:53:09 by gguedes           #+#    #+#             */
/*   Updated: 2022/05/30 12:06:41 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int	check_new_line(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*create_line(char *s)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	new_str = (char *)malloc(i + 1 * sizeof(char));
	if (!new_str)
		return (NULL);
	j = 0;
	while (j < i)
	{
		new_str[j] = s[j];
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strjoin(char *s, char *tmp)
{
	int		i;
	char	*new_str;

	new_str = (char *)malloc(ft_strlen(s) + ft_strlen(tmp) + 1 * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	if (s)
	{
		while (*s)
		{
			new_str[i++] = *s;
			s++;
		}
	}
	if (tmp)
	{
		while (*tmp)
		{
			new_str[i++] = *tmp;
			tmp++;
		}
	}
	new_str[i] = '\0';
	return (new_str);
}
