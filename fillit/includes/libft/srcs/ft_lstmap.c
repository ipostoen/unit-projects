/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogokar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 20:08:01 by dogokar           #+#    #+#             */
/*   Updated: 2016/01/12 11:51:09 by dogokar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlist;
	t_list *tmp2;

	if (!(newlist = (t_list*)ft_memalloc(sizeof(t_list))))
		return (NULL);
	tmp2 = f(lst);
	newlist = tmp2;
	while (lst->next)
	{
		tmp2->next = ft_lstnew(lst->content, lst->content_size);
		lst = lst->next;
		tmp2->next = f(lst);
		tmp2 = tmp2->next;
	}
	return (newlist);
}
