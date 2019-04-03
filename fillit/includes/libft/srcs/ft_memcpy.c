/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogokar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:42:18 by dogokar           #+#    #+#             */
/*   Updated: 2015/12/10 02:52:02 by dogokar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*v_dst;
	unsigned char	*v_src;

	i = 0;
	v_dst = (unsigned char *)dst;
	v_src = (unsigned char *)src;
	while (n)
	{
		v_dst[i] = v_src[i];
		i++;
		n--;
	}
	return (dst);
}
