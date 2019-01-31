/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freelst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 11:36:11 by hutricot          #+#    #+#             */
/*   Updated: 2019/01/31 11:39:42 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freelst(t_list **alst)
{
	t_list  *tmp;

	while (*alst != NULL)
	{
		tmp = (*alst)->next;
		free((*alst)->content);
		free(*alst);
		*alst = tmp;
	}
	free(*alst);
	*alst = (NULL);
}
