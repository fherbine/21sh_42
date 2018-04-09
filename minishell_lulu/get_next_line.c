/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:53:45 by llacaze           #+#    #+#             */
/*   Updated: 2018/03/06 13:41:02 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_check_eol(char *buf)
{
	int		j;

	j = 0;
	if (buf != NULL)
	{
		while (buf[j] != EOL && buf[j])
			j++;
		if (buf[j] == EOL)
		{
			buf[j] = '\0';
			return (j);
		}
	}
	return (-1);
}

int		ft_check_buf(char **buf, char *stock, char **line)
{
	char	*tmp;
	int		endline;

	tmp = *buf;
	*buf = ft_strjoin(*buf, stock);
	free(tmp);
	ft_bzero(stock, BUFF_SIZE + 1);
	endline = ft_check_eol(*buf);
	if (endline > -1)
	{
		*line = ft_strdup(*buf);
		tmp = *buf;
		*buf = ft_strdup(*buf + endline + 1);
		free(tmp);
		return (1);
	}
	return (0);
}

int		ft_free(char **buf, char **line, char *stock, const int fd)
{
	if (ft_check_buf(&buf[fd], stock, line) == 1)
		return (1);
	else if (ft_check_buf(&buf[fd], stock, line) == 0 && ft_strlen(buf[fd]) > 0)
	{
		*line = ft_strdup(buf[fd]);
		ft_strdel(&buf[fd]);
		ft_strdel(&stock);
		return (1);
	}
	ft_strdel(&stock);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*buf[217483648];
	char		*stock;
	int			check_buf;

	stock = ft_strnew(BUFF_SIZE + 1);
	if (fd < 0 || BUFF_SIZE <= 0 || !line || read(fd, stock, 0) < 0)
		return (-1);
	while (read(fd, stock, BUFF_SIZE) > 0)
	{
		check_buf = ft_check_buf(&buf[fd], stock, line);
		free(stock);
		if (check_buf == 1)
			return (1);
		stock = ft_strnew(BUFF_SIZE + 1);
	}
	if (ft_free(buf, line, stock, fd) == 1)
		return (1);
	return (0);
}
