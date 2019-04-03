/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipostoen <ipostoen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 00:26:09 by ipostoen          #+#    #+#             */
/*   Updated: 2017/11/24 01:21:47 by ipostoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *buf;

	if (!lst)
		return (NULL);
	buf = f(lst);
	new = buf;
	while (lst->next)
	{
		lst = lst->next;
		if (!(buf->next = f(lst)))
		{
			free(buf->next);
			return (NULL);
		}
		buf = buf->next;
	}
	return (new);
}
