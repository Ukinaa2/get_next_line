/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:53:09 by gguedes           #+#    #+#             */
/*   Updated: 2022/05/28 15:59:30 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

//strlen
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

//verifica se existe uma quebra de linha na string
int	new_line(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

//cria a string que sera retornada
char	*create_line(char *s)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	while (s[i] != '\n')
		i++;
	i++;
	new_str = (char *)malloc(i + 1 * sizeof(char));
	if (!new_str)
		return (0);
	j = 0;
	while (j < i)
	{
		new_str[j] = s[j];
		j++;
	}
	printf("\n\nstr: \"%s\"\n\n", g_str);
	new_str[i] = '\0';
	return (new_str);
}

//cria uma nova string, que é a soma das duas strings passadas
char	*ft_strjoin(char *s, char *tmp)
{
	int		i;
	char	*new_str;

	new_str = (char *)malloc(ft_strlen(s) + ft_strlen(tmp) + 1 * sizeof(char));
	if (!new_str)
		return (0);
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
