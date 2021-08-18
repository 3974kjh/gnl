/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <jukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:06:09 by jukim             #+#    #+#             */
/*   Updated: 2021/06/01 14:35:48 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

ssize_t	ft_check_nline(char *buf)
{
	ssize_t i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

ssize_t	ft_tsplit(char **line, char **buf_save, ssize_t nline_idx)
{
	char *tmp;

	(*buf_save)[nline_idx] = '\0';
	if (!(*line = ft_strdup(*buf_save)))
		return (-1);
	if (ft_strlen(*buf_save + nline_idx + 1) != 0)
	{
		if (!(tmp = ft_strdup(*buf_save + nline_idx + 1)))
			return (-1);
		free(*buf_save);
		*buf_save = tmp;
	}
	else
	{
		free(*buf_save);
		*buf_save = 0;
	}
	return (1);
}

ssize_t	ft_full_split(char **line, char **buf_save)
{
	ssize_t			nline_idx;

	if ((*buf_save) && ((nline_idx = ft_check_nline(*buf_save)) >= 0))
		return (ft_tsplit(line, buf_save, nline_idx));
	else if (!*buf_save)
	{
		if (!(*line = ft_strdup("")))
			return (-1);
		return (0);
	}
	else
	{
		*line = *buf_save;
		*buf_save = 0;
		return (0);
	}
}

int		get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*buf_save[OPEN_MAX];
	ssize_t			read_size;
	ssize_t			nline_idx;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) != 0)
	{
		if (read_size < 0)
			return (-1);
		buf[read_size] = '\0';
		if (!(buf_save[fd] = ft_strjoin(buf_save[fd], buf)))
			return (-1);
		if ((nline_idx = ft_check_nline(buf_save[fd])) >= 0)
			return (ft_tsplit(line, &buf_save[fd], nline_idx));
	}
	return (ft_full_split(line, &buf_save[fd]));
}
