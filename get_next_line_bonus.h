/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:10:16 by gguedes           #+#    #+#             */
/*   Updated: 2022/06/03 13:17:00 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*check_new_line(int fd, char *str, char *buffer);
char	*find_next_line(char *str);
size_t	ft_strlen(const char *str);
char	*create_line(const char *str);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *str);

#endif
