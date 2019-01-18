/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:15:38 by hutricot          #+#    #+#             */
/*   Updated: 2018/11/15 13:54:12 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*nlst;
	t_list	*slst;

	tmp = f(lst);
	if (lst == 0 || f == 0)
		return (NULL);
	if ((nlst = ft_lstnew(tmp->content, tmp->content_size)) == 0)
		return (0);
	slst = nlst;
	lst = lst->next;
	while (lst != NULL)
	{
		tmp = f(lst);
		if ((nlst->next = ft_lstnew(tmp->content, tmp->content_size)) == 0)
			return (0);
		nlst = nlst->next;
		lst = lst->next;
	}
	return (slst);
}
