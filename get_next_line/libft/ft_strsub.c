/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipostoen <ipostoen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 03:02:01 by ipostoen          #+#    #+#             */
/*   Updated: 2017/11/22 20:20:40 by ipostoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	size_t	i;

	i = 0;
	if (!s || start > ft_strlen(s))
		return (NULL);
	fresh = (char *)malloc(sizeof(char) * len + 1);
	if (!fresh)
		return (NULL);
	while (len)
	{
		fresh[i] = s[start];
		i++;
		len--;
		start++;
	}
	fresh[i] = '\0';
	return (fresh);
}
