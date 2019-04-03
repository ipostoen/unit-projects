/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogokar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 22:44:40 by dogokar           #+#    #+#             */
/*   Updated: 2015/12/29 23:38:41 by dogokar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	ft_isneg(int *n, char c)
{
	c = '-';
	(*n == -2147483648) ? (*n = 2147483647) : (*n *= -1);
	return (c);
}

static	int		ft_length_int(int n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		isave;
	int		nsave;

	i = ft_length_int(n);
	isave = i;
	if ((str = (char *)malloc(sizeof(char) * (i + 2))) == NULL)
		return (NULL);
	nsave = n;
	if (n < 0)
		str[0] = ft_isneg(&n, str[0]);
	else
		str[i--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[i] = '0' + n % 10;
		n /= 10;
		i--;
	}
	(nsave == -2147483648) ? (str[isave] += 1) : (str[0] = str[0]);
	str[isave + 1] = '\0';
	return (str);
}
