/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipostoen <ipostoen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 00:11:23 by ipostoen          #+#    #+#             */
/*   Updated: 2017/11/18 18:22:00 by ipostoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t my_size;

	my_size = (size_t)(ft_strlen(dst) + ft_strlen((char*)src));
	if (ft_strlen(dst) >= dstsize)
		return (ft_strlen((char*)src) + dstsize);
	dstsize = dstsize - ft_strlen(dst) - 1;
	while (*dst)
		dst++;
	while (*(unsigned char*)src && dstsize)
	{
		*(unsigned char*)dst++ = *(unsigned char*)src++;
		dstsize--;
	}
	*dst = '\0';
	return (my_size);
}
