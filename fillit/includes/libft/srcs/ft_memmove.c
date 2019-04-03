/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogokar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 23:47:18 by dogokar           #+#    #+#             */
/*   Updated: 2015/12/30 03:51:54 by dogokar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *tmp;
	unsigned char *result;

	tmp = ft_memalloc(len);
	result = ft_memcpy(tmp, src, len);
	dst = ft_memcpy(dst, tmp, len);
	free(tmp);
	return (dst);
}
