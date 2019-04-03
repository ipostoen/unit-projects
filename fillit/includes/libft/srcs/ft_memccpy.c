/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogokar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 19:15:02 by dogokar           #+#    #+#             */
/*   Updated: 2015/12/10 02:22:06 by dogokar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int				i;
	unsigned char	*v_dst;
	unsigned char	*v_src;

	i = 0;
	v_dst = (unsigned char *)dst;
	v_src = (unsigned char *)src;
	while (n)
	{
		v_dst[i] = v_src[i];
		if (v_src[i] == (unsigned char)c)
			return (dst + i + 1);
		n--;
		i++;
	}
	return (NULL);
}
