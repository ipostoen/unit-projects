/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogokar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 03:02:16 by dogokar           #+#    #+#             */
/*   Updated: 2015/12/10 02:52:26 by dogokar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *dst;

	if (((dst = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))) == NULL))
		return (NULL);
	dst = ft_strcpy(dst, s1);
	return (dst);
}
