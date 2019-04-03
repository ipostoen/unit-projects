/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipostoen <ipostoen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 02:56:22 by ipostoen          #+#    #+#             */
/*   Updated: 2017/11/19 18:50:36 by ipostoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *result;

	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	ft_bzero(result, size + 1);
	return (result);
}
