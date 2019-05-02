/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:54:50 by mipham            #+#    #+#             */
/*   Updated: 2018/03/23 16:08:02 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strclen(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		read_left(t_gnl *gnl, char **line, char c)
{
	char	*tmp;
	int		len;
	int		s_len;

	len = (int)ft_strlen(gnl->str);
	if (c != 0)
	{
		s_len = ft_strclen(gnl->str, c);
		if (!(*line = ft_strsub(gnl->str, 0, s_len)))
			return (-1);
		tmp = gnl->str;
		if (!(gnl->str = ft_strsub(gnl->str, s_len + 1, len - s_len - 1)))
			return (-1);
		free(tmp);
		return (1);
	}
	else
	{
		if (!(*line = ft_strsub(gnl->str, 0, len)))
			return (-1);
		gnl->str ? free(gnl->str) : 0;
		if (!(gnl->str = ft_strnew(0)))
			return (-1);
		return (1);
	}
}

int		read_line(t_gnl *gnl, char **line)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	while ((gnl->r_stt = read(gnl->fd, buf, BUFF_SIZE)) > 0)
	{
		buf[gnl->r_stt] = '\0';
		tmp = gnl->str;
		if (!(gnl->str = ft_strjoin(gnl->str, buf)))
			return (-1);
		free(tmp);
		if (ft_strclen(gnl->str, '\n') != -1)
			return (read_left(gnl, line, '\n'));
	}
	if (gnl->r_stt == 0 && (int)ft_strlen(gnl->str) > 0)
		return (read_left(gnl, line, 0));
	return (gnl->r_stt);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*gnl;
	t_gnl			*tmp;

	if (fd < 0 || !line)
		return (-1);
	tmp = gnl;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (!tmp)
	{
		if (!(tmp = (t_gnl *)malloc(sizeof(t_gnl))))
			return (-1);
		tmp->str = ft_strnew(0);
		tmp->fd = fd;
		tmp->next = gnl;
		gnl = tmp;
	}
	if (ft_strclen(tmp->str, '\n') != -1)
		return (read_left(tmp, line, '\n'));
	return (read_line(tmp, line));
}
