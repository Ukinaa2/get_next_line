/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:53:09 by gguedes           #+#    #+#             */
/*   Updated: 2022/05/31 16:03:36 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)str + i);
		i++;
	}
	return (0);
}

char	*create_new_line(const char *str)
{
	int		i;
	int		j;
	char	*new_str;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\n')
		i++;
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

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	char	*new_str;

	new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	if (s1)
		while (*s1)
			new_str[i++] = *s1++;
	if (s2)
		while (*s2)
			new_str[i++] = *s2++;
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strdup(const char *str)
{
	int		i;
	char	*new_str;

	if (!str)
		return (NULL);
	new_str = (char *)malloc(ft_strlen(str) + 1 * sizeof(char));
	if (!new_str)
		return (0);
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
