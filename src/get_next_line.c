/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:19:37 by maduhoux          #+#    #+#             */
/*   Updated: 2018/06/25 16:42:43 by maduhoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_read_file(char **line, char **buf_static, int fd)
{
	char	*n_pos;
	int		ret;
	int		length;
	char	buf[BUFF_SIZE + 1];

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		n_pos = *line;
		*line = ft_strjoin(n_pos, buf);
		free(n_pos);
		if ((n_pos = ft_strchr(*line, '\n')))
		{
			*buf_static = ft_strdup(n_pos + 1);
			length = n_pos - *line;
			n_pos = *line;
			*line = ft_strsub(n_pos, 0, length);
			free(n_pos);
			ret = 1;
			break ;
		}
	}
	return (ret);
}

static int	ft_if_buf(char **buf_static, char **line)
{
	char		*tmp;
	char		*tmp1;

	if ((tmp = ft_strchr(*buf_static, '\n')))
	{
		free(*line);
		*line = ft_strsub(*buf_static, 0, tmp - *buf_static);
		tmp1 = ft_strdup(tmp + 1);
		free(*buf_static);
		*buf_static = tmp1;
		return (1);
	}
	free(*line);
	*line = ft_strdup(*buf_static);
	free(*buf_static);
	*buf_static = NULL;
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	int			read_int;
	static char	*buf_static[OPEN_MAX] = {NULL};

	if (fd < 0 || read(fd, NULL, 0) == -1 || line == NULL)
		return (-1);
	if (!(*line = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (buf_static[fd])
	{
		if (ft_if_buf(&buf_static[fd], line))
			return (1);
	}
	if ((read_int = ft_read_file(&(*line), &buf_static[fd], fd)) == 0 \
			&& !buf_static[fd] && !ft_strlen(*line))
		return (0);
	return (1);
}
