/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipostoen <ipostoen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 15:45:44 by ipostoen          #+#    #+#             */
/*   Updated: 2017/11/18 18:17:15 by ipostoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char *res;

	res = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!res)
		return (NULL);
	return (ft_strcpy(res, str));
}
