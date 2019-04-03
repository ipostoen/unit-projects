/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strntrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipostoen <ipostoen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 20:46:00 by ipostoen          #+#    #+#             */
/*   Updated: 2017/12/03 20:46:20 by ipostoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strntrim(char const *s, char c)
{
	long	size;
	char	*fresh;
	size_t	j;

	j = 0;
	if (!s)
		return (NULL);
	size = ft_strlen(s);
	while (s[size - 1] == c)
		size--;
	while (*s == c)
	{
		size--;
		s++;
	}
	if (size < 0)
		size = 0;
	if (!(fresh = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (size--)
		fresh[j++] = *s++;
	fresh[j] = '\0';
	return (fresh);
}
