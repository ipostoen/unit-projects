/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ila <ila@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 13:58:55 by ipostoen          #+#    #+#             */
/*   Updated: 2018/01/27 04:49:53 by ila              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_str_oper(char *str, size_t size)
{
	char *new_buf;

	if (!str)
	{
		new_buf = ft_strnew(size);
		return (new_buf);
	}
	new_buf = ft_strnew(ft_strlen(str) + size);
	ft_strcpy(new_buf, str);
	free(str);
	return (new_buf);
}

int     ft_check_str(char **line, char *tmp)
{
	int		len;
	char	*buf;

	if ((buf = ft_strchr(tmp, '\n')))
	{
		*line = ft_str_oper(*line, buf - tmp);
		ft_strncat(*line, tmp, buf - tmp);
		ft_memmove(tmp, buf + 1, ft_strlen(buf));
		return (1);
	}
	if ((len = ft_strlen(tmp)))
	{
		*line = ft_str_oper(*line, len);
		ft_strncat(*line, tmp, len);
		*tmp = '\0';
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int rd;
	static char *tmp[8146];

	if (fd < 0 || BUFF_SIZE < 1 || !line ||
	(!tmp[fd] && !(tmp[fd] = ft_strnew(BUFF_SIZE))))
		return (-1);
	*line = NULL;
	if (ft_check_str(line, tmp[fd]))
		return (1);
	while ((rd = read(fd, tmp[fd], BUFF_SIZE)) > 0)
	{
		tmp[fd][rd] = '\0';
		if (ft_check_str(line, tmp[fd]))
			return (1);
	}
	if (rd < 0)
		return (-1);
	if (*line)
		return (1);
	ft_strdel(&tmp[fd]);
	return (0);
}