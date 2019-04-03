/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipostoen <ipostoen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 21:55:52 by ila               #+#    #+#             */
/*   Updated: 2017/11/24 01:28:48 by ipostoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t i;
	size_t a;

	i = 0;
	if (find[0] == '\0')
		return ((char *)str);
	a = ft_strlen(find);
	while (*str != '\0' && len-- >= a)
	{
		if (*str == *find && ft_memcmp(str, find, a) == 0)
			return ((char *)str);
		str++;
	}
	return (0);
}
