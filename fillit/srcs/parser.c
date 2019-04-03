/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipostoen <ipostoen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 22:44:21 by ipostoen          #+#    #+#             */
/*   Updated: 2017/12/11 16:00:40 by ipostoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	*ft_strntrim(char const *s, char c)
{
	long	size;
	char	*fresh;
	size_t	j;

	j = 0;
	if (!s)
		return (NULL);
	size = ft_strlen(s);
	while (s[size - 1] == c)
		size--;
	while (*s == c)
	{
		size--;
		s++;
	}
	if (size < 0)
		size = 0;
	if (!(fresh = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (size--)
		fresh[j++] = *s++;
	fresh[j] = '\0';
	return (fresh);
}

int		ft_is_figure(int fd, char *buffer, int size, int read_size)
{
	if ((read_size = read(fd, buffer, 21)))
	{
		if (buffer[4] == '\n' && buffer[9] == '\n'
			&& buffer[14] == '\n' && buffer[19] == '\n')
		{
			buffer[4] = '.';
			buffer[9] = '.';
			buffer[14] = '.';
			buffer[19] = '.';
			if (read_size == 21 && buffer[20] != '\n')
			{
				free(buffer);
				ft_error();
			}
			buffer[20] = '.';
		}
		else
		{
			free(buffer);
			ft_error();
		}
	}
	if(read_size == 0 && size == 21)
		ft_error();
	return (read_size);
}

t_fig	*ft_figure_xy(t_fig *figure, char *buffer)
{
	int		i;
	int 	x;
	int 	y;
	int 	cnt;

	cnt = 0;
	i = -1;
	y = 0;
	x = 0;
	while (buffer[++i])
		if (buffer[i] == '.')
			x++;
		else if (buffer[i] == '\n')
		{
			y++;
			x = 0;
		}
		else if (buffer[i] == '#')
		{
			figure->x[cnt] = x++;
			figure->y[cnt++] = y;
		}
	return (figure);
}

char	*ft_what_figure(char *buffer)
{
	buffer = ft_strntrim(buffer, '.');
	FIND_FIGURE(buffer, "#....#....#....#", "#\n#\n#\n#");
	FIND_FIGURE(buffer, "####", "####");
	FIND_FIGURE(buffer, "###..#", "###\n#");
	FIND_FIGURE(buffer, "###...#", "###\n.#");
	FIND_FIGURE(buffer, "###....#", "###\n..#");
	FIND_FIGURE(buffer, "##...##", "##\n##");
	FIND_FIGURE(buffer, "##...#....#", "##\n#\n#");
	FIND_FIGURE(buffer, "##....##", "##\n.##");
	FIND_FIGURE(buffer, "##....#....#", "##\n.#\n.#");
	FIND_FIGURE(buffer, "#....##...#", "#\n##\n#");
	FIND_FIGURE(buffer, "#....###", "#\n###");
	FIND_FIGURE(buffer, "#....#....##", "#\n#\n##");
	FIND_FIGURE(buffer, "#....##....#", "#\n##\n.#");
	FIND_FIGURE(buffer, "#...##...#", ".#\n##\n#");
	FIND_FIGURE(buffer, "#...###", ".#\n###");
	FIND_FIGURE(buffer, "##..##", ".##\n##");
	FIND_FIGURE(buffer, "#...##....#", ".#\n##\n.#");
	FIND_FIGURE(buffer, "#..###", "..#\n###");
	FIND_FIGURE(buffer, "#....#...##", ".#\n.#\n##");
	free(buffer);
	ft_error();
	return (0);
}

t_fig	*ft_read_figures(int fd, t_fig *figure)
{
	char		*buffer;
	char		symbol;
	t_fig		*tmp;
	int 		size;

	size = 21;
	symbol = 65;
	if (!(buffer = (char*)malloc(21)))
		ft_error();
	buffer[21] = '\0';
	tmp = figure;
	while ((size = ft_is_figure(fd, buffer, size, 0)) != 0)
	{
		tmp->c = symbol++;
		tmp = ft_figure_xy(tmp, ft_what_figure(buffer));
		if (!(tmp->next = (t_fig *)malloc(sizeof(t_fig))))
			ft_error();
		tmp = tmp->next;
		if (symbol > 91)
			ft_error();
	}
	free(buffer);
	tmp->next = NULL;
	return(figure);
}

t_fig	*ft_open(char *str)
{
	t_fig	*figure;
	int 	fd;

	if (!(figure = (t_fig *)malloc(sizeof(t_fig))))
		ft_error();

	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error();
	figure = ft_read_figures(fd, figure);
	if (close(fd) == -1)
		ft_error();
	return figure;
}
