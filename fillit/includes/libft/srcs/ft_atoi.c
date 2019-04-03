/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogokar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 22:39:55 by dogokar           #+#    #+#             */
/*   Updated: 2015/12/10 02:11:40 by dogokar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int result;
	int pos;

	result = 0;
	pos = 1;
	while ((*str > 8 && *str < 14) || (*str == ' '))
		str++;
	if ((*str == '-') || (*str == '+'))
		if ((pos = ((*str == '-') ? -pos : pos)))
			str++;
	while (*str == '0')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + ((char)*str - 48);
		str++;
	}
	return (result * pos);
}
