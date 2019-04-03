/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipostoen <ipostoen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 14:50:45 by ipostoen          #+#    #+#             */
/*   Updated: 2017/11/23 01:54:40 by ipostoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static	int		ft_countwrds(const char *str, char c)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			word++;
		i++;
	}
	if (str[0] != '\0')
		word++;
	return (word);
}

static	char	*ft_wrdofstr(const char *str, char c, int *i)
{
	char	*s;
	int		j;

	if (!(s = (char *)malloc(sizeof(s) * (ft_strlen(str)))))
		return (NULL);
	j = 0;
	while (str[*i] != c && str[*i])
	{
		s[j] = str[*i];
		j++;
		*i += 1;
	}
	s[j] = '\0';
	while (str[*i] == c && str[*i])
		*i += 1;
	return (s);
}

char			**ft_strsplit(const char *s, char c)
{
	int		i;
	int		j;
	int		numofwrd;
	char	**result;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	numofwrd = ft_countwrds(s, c);
	if (!(result = (char **)malloc(sizeof(result) * (numofwrd + 2))))
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	while (j < numofwrd && s[i])
	{
		result[j] = ft_wrdofstr(s, c, &i);
		j++;
	}
	result[j] = NULL;
	return (result);
}
