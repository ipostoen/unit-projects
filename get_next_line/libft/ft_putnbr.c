/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipostoen <ipostoen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 01:42:13 by ipostoen          #+#    #+#             */
/*   Updated: 2017/11/23 03:49:13 by ipostoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_put(unsigned int n)
{
	if (n / 10)
		ft_put(n / 10);
	ft_putchar(n % 10 + '0');
}

void			ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_put(-n);
	}
	else
		ft_put(n);
}
