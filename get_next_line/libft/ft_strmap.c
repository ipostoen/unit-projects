/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipostoen <ipostoen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 01:57:25 by ipostoen          #+#    #+#             */
/*   Updated: 2017/11/19 02:54:00 by ipostoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	fresh = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!fresh)
		return (0);
	while (*s != '\0')
	{
		fresh[i] = f(*s);
		s++;
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
