/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipostoen <ipostoen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 22:36:59 by ipostoen          #+#    #+#             */
/*   Updated: 2017/11/18 18:35:37 by ipostoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	size_t	t;

	i = 0;
	t = 0;
	while (s1[i])
		i++;
	while (t < n && s2[t])
	{
		s1[i] = s2[t];
		i++;
		t++;
	}
	s1[i] = '\0';
	return (s1);
}
