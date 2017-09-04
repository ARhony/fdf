/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 19:07:28 by aramon            #+#    #+#             */
/*   Updated: 2016/11/25 22:01:00 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*result;
	t_list		*tmp;
	t_list		*t2;

	if (lst == NULL || f == NULL)
		return (NULL);
	t2 = f(lst);
	if ((result = ft_lstnew(t2->content, t2->content_size)) != NULL)
	{
		tmp = result;
		lst = lst->next;
		while (lst != NULL)
		{
			t2 = f(lst);
			if ((tmp->next = ft_lstnew(t2->content, t2->content_size)) == NULL)
				return (NULL);
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	return (result);
}
