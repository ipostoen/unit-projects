/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipostoen <ipostoen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 22:44:21 by ipostoen          #+#    #+#             */
/*   Updated: 2017/12/11 16:00:40 by ipostoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fig			*ft_update_xy(t_fig *figure, int x, int y)
{
	int		xmin;
	int		ymin;
	int		i;

	xmin = 200;
	ymin = 200;
	i = 0;
	while (i != 4)
	{
		if (figure->x[i] < xmin)
			xmin = figure->x[i];
		if (figure->y[i] < ymin)
			ymin = figure->y[i];
		i++;
	}
	i = 0;
	while (i != 4)
	{
		figure->x[i] = figure->x[i] - xmin + x;
		figure->y[i] = figure->y[i] - ymin + y;
		i++;
	}
	return (figure);
}
