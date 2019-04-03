/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipostoen <ipostoen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 00:36:13 by ipostoen          #+#    #+#             */
/*   Updated: 2017/11/23 01:23:34 by ipostoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_itoa(int n)
{
	int		i;
	int		neg;
	int		bufer;
	char	*result;

	neg = 0;
	if (n < 0)
		neg = 1;
	bufer = n;
	i = 1;
	while ((bufer /= 10))
		i++;
	result = ft_strnew(i + neg);
	if (!result)
		return (NULL);
	while (i--)
	{
		result[i + neg] = (neg ? -(n % 10) : (n % 10)) + '0';
		n /= 10;
	}
	if (neg)
		result[0] = '-';
	return (result);
}
