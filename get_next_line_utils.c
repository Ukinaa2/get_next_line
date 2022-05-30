/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:53:09 by gguedes           #+#    #+#             */
/*   Updated: 2022/05/30 13:58:34 by gguedes          ###   ########.fr       */
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
	while (*s1)
	{
		new_str[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		new_str[i++] = *s2;
		s2++;
	}
	new_str[i] = '\0';

	return (new_str);
}

int	main(void)
{
	int		i;
	char	*str;

	str = ft_strjoin("a", "abcd");
	printf("%s\n", str);
	i = ft_strlen(str);
	printf("%i\n", i);
	return (0);
}
