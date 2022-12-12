/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:33:01 by aconta            #+#    #+#             */
/*   Updated: 2022/12/11 14:29:34 by aconta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*free_joined_save(char *save, char *buf)
{
	char	*remaining;

	if (!save)
	{
		save = malloc(sizeof (char));
		if (!save)
			return (NULL);
	}
	remaining = ft_strjoin(save, buf);
	free(save);
	return (remaining);
}

char	*get_a_line(int fd, char *save)
{
	char	*buf;
	int		read_bytes;

	buf = malloc(sizeof (char) *(BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_bytes = 1;
	while (read_bytes != 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1 || read_bytes == 0)
		{
			free(buf);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		save = free_joined_save(save, buf);
		if (find_index(save, '\n') >= 0)
			break ;
	}
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;
	int			i;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	save = get_a_line(fd, save);
	if (!save)
		return (NULL);
	i = find_index(save, '\n');
	if (i < 0)
		return (NULL);
	line = ft_substr(save, 0, i + 1);
	if (!line)
		return (NULL);
	save = ft_substr(save, i + 1, (find_index(save, '\0') - i));
	if (ft_strlen(save) == 0 && save)
		free(save);
	return (line);
}
