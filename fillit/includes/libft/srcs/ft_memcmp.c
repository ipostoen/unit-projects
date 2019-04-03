/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogokar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 02:36:01 by dogokar           #+#    #+#             */
/*   Updated: 2015/12/29 05:14:19 by dogokar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *v_s1;
	unsigned char *v_s2;

	v_s1 = (unsigned char *)s1;
	v_s2 = (unsigned char *)s2;
	while (n--)
	{
		if (*v_s1 != *v_s2)
			return (*v_s1 - *v_s2);
		v_s1++;
		v_s2++;
	}
	return (0);
}
