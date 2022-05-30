/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:53:09 by gguedes           #+#    #+#             */
/*   Updated: 2022/05/30 14:08:59 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*new_str;

	new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (*s1)
		new_str[i++] = *s1++;
	while (*s2)
		new_str[i++] = *s2++;
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*new_str;

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

int	main(void)
{
	int		i;
	char	*str1;
	char	*str2;

	str1 = ft_strjoin("abcd", "efgh");
	printf("%s\n", str1);
	i = ft_strlen(str1);
	printf("%i\n", i);
	str2 = ft_strdup(str1);
	printf("%s\n", str2);
	return (0);
}
