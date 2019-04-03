/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogokar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 00:07:13 by dogokar           #+#    #+#             */
/*   Updated: 2015/12/30 03:53:02 by dogokar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*v_s;

	v_s = (unsigned char *)s;
	while (n)
	{
		if (*v_s == (unsigned char)c)
			return ((void *)(v_s));
		v_s++;
		n--;
	}
	return (NULL);
}
