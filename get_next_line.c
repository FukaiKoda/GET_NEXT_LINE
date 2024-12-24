/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:08:42 by habdella          #+#    #+#             */
/*   Updated: 2024/11/03 13:09:29 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update(char *contain)
{
	char	*p;
	int		i;

	i = 0;
	if (!contain)
		return (NULL);
	while (contain[i] && contain[i] != '\n')
		i++;
	if (contain[i])
		i++;
	p = ft_strdup(contain + i);
	return (p);
}

char	*get_container(char *contain, char *buff, int fd)
{
	char	*temp;
	ssize_t	reader;

	reader = read(fd, buff, BUFFER_SIZE);
	if (reader < 0 || !buff)
		return (NULL);
	while (reader > 0)
	{
		buff[reader] = '\0';
		if (!contain)
			contain = ft_strdup(buff);
		else if (buff)
		{
			temp = contain;
			contain = ft_strjoin(contain, buff);
			free(temp);
		}
		if (ft_strchr(contain, '\n') || reader < BUFFER_SIZE)
			return (contain);
		reader = read(fd, buff, BUFFER_SIZE);
	}
	if (contain)
		return (contain);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*contain;
	char		*buff;
	char		*line;
	char		*temp;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	contain = get_container(contain, buff, fd);
	free(buff);
	if (!contain || !ft_strlen(contain))
	{
		free(contain);
		return (NULL);
	}
	line = ft_strdupnl(contain);
	temp = contain;
	contain = update(contain);
	free(temp);
	return (line);
}
