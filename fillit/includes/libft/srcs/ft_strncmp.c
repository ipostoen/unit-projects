/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogokar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 05:43:41 by dogokar           #+#    #+#             */
/*   Updated: 2015/12/29 05:13:14 by dogokar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*v_s1;
	unsigned char	*v_s2;

	i = 0;
	v_s1 = (unsigned char *)s1;
	v_s2 = (unsigned char *)s2;
	while ((v_s1[i] != '\0' || v_s2[i] != '\0') && n)
	{
		if (v_s1[i] != v_s2[i])
			return (v_s1[i] - v_s2[i]);
		i++;
		n--;
	}
	return (0);
}
