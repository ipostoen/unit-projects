/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipostoen <ipostoen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 22:44:21 by ipostoen          #+#    #+#             */
/*   Updated: 2017/12/11 16:00:40 by ipostoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**ft_reset(char **src, t_fig *figure, int max)
{
	int		x;
	int		y;

	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (src[y][x] == figure->c)
				src[y][x] = '.';
			x++;
		}
		y++;
	}
	return (src);
}

static char		**ft_save(char **src, t_fig *figure, int max)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (figure->x[i] == x && figure->y[i] == y)
			{
				src[y][x] = figure->c;
				i++;
			}
			x++;
		}
		src[y][x] = '\0';
		y++;
	}
	src[y] = NULL;
	return (src);
}

static int		ft_check(char **src, t_fig *figure, int max)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (figure->x[i] == x && figure->y[i] == y && src[y][x] != '.')
				return (0);
			else if (figure->x[i] == x && figure->y[i] == y)
				i++;
			x++;
		}
		y++;
	}
	if (i < 4)
		return (0);
	return (1);
}

static char		**ft_final_str(char **src, t_fig *figure, int max)
{
	int		x;
	int		y;
	char	**tmp;

	if (!figure->next)
		return (src);
	tmp = NULL;
	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			figure = ft_update_xy(figure, x, y);
			if (ft_check(src, figure, max))
				tmp = ft_final_str(ft_save(src, figure, max), figure->next, max);
			if (tmp)
				return (tmp);
			src = ft_reset(src, figure, max);
			++x;
		}
		++y;
	}
	return (NULL);
}

char			**ft_result(t_fig *figure, int max)
{
	char	**src;

	src = NULL;
	while (!src)
	{
		src = ft_fill_empty(src, max);
		src = ft_final_str(src, figure, max);
		max++;
	}
	return (src);
}
