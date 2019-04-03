/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipostoen <ipostoen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 15:30:19 by ipostoen          #+#    #+#             */
/*   Updated: 2017/11/23 01:09:19 by ipostoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*res;
	unsigned int	i;
	unsigned int	a;
	unsigned int	b;

	i = 0;
	b = 0;
	if (!s)
		return (NULL);
	a = ft_strlen(s);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	if (s[i] == '\0')
		return (ft_strdup("\0"));
	while (s[a - 1] == ' ' || s[a - 1] == '\n' || s[a - 1] == '\t')
		a--;
	if (!(res = ft_strnew(a - i)))
		return (NULL);
	while (i < a)
		res[b++] = s[i++];
	res[b] = '\0';
	return (res);
}
