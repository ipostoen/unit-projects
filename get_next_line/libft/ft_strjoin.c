/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipostoen <ipostoen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 03:38:20 by ipostoen          #+#    #+#             */
/*   Updated: 2017/11/22 20:13:01 by ipostoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*fresh;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	fresh = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!fresh)
		return (NULL);
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != '\0')
		{
			fresh[i++] = *s1;
			s1++;
		}
		if (*s1 == '\0')
		{
			fresh[i++] = *s2;
			s2++;
		}
	}
	fresh[i] = '\0';
	return (fresh);
}
