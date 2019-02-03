/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iso.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:41:55 by hutricot          #+#    #+#             */
/*   Updated: 2019/01/31 12:07:07 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

void	ft_iso(t_ptr *ptr)
{
	ptr->o[X] = 250;
	ptr->o[Y] = 250;
	ptr->iso[0][0] = 20;
	ptr->iso[0][1] = -1;
	ptr->iso[1][0] = 2;
	ptr->iso[1][1] = 10;
	ptr->iso[2][0] = 2;
	ptr->iso[2][1] = 1;
}
