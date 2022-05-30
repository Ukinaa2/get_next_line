/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:53:28 by gguedes           #+#    #+#             */
/*   Updated: 2022/05/30 12:40:42 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int	arg;
	int	i;
	int	fd;

	if (argc > 1)
		arg = atoi(argv[1]);
	else
	{
		printf("missing number of lines to read\n");
		return (0);
	}
	i = 0;
	fd = open("file.txt", O_RDONLY);
	while (i < arg)
	{
		printf("%i. %s", i + 1, get_next_line(fd));
		i++;
	}
	close(fd);
	return (0);
}
