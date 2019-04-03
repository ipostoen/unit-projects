/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipostoen <ipostoen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 22:44:21 by ipostoen          #+#    #+#             */
/*   Updated: 2017/12/11 16:00:40 by ipostoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	ft_error(void)
{
	write(1, "error\n", 6);
	exit (0);
}

int		main(int argc, char *argv[])
{
	t_fig	*figure;
	char	**result;

	if (argc != 2)
		ft_error();

	figure = ft_open(argv[1]);
	result = ft_result(figure, ft_figure_size(figure));
	free(figure);

	while (*result)
		ft_putendl(*result++);
	return (0);
}
