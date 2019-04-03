/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogokar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:37:16 by dogokar           #+#    #+#             */
/*   Updated: 2015/12/10 02:47:26 by dogokar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	int				i;
	unsigned char	*v_b;

	i = 0;
	v_b = (unsigned char *)b;
	while (n)
	{
		v_b[i] = c;
		i++;
		n--;
	}
	return (b);
}
