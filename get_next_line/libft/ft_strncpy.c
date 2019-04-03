/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipostoen <ipostoen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 21:31:44 by ipostoen          #+#    #+#             */
/*   Updated: 2017/11/18 18:18:03 by ipostoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int i;

	i = 0;
	while (src[i] && len)
	{
		dst[i] = src[i];
		len--;
		i++;
	}
	while (len)
	{
		dst[i] = '\0';
		len--;
		i++;
	}
	return (dst);
}
