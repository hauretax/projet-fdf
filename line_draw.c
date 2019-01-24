/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 12:55:15 by hutricot          #+#    #+#             */
/*   Updated: 2019/01/24 13:43:35 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"
#include <unistd.h>

int		ft_abs(int nb)
{
	if (nb < 0)
		return -nb;
	else
		return nb;
}

void	right(t_line *l1, void *param, char c)
{
	t_ptr *w1;

	w1 = (t_ptr *)param;
	l1->x = l1->x0;
	l1->y = l1->y0;
	l1->dy = ft_abs(l1->dy);
	l1->dx = ft_abs(l1->dx);
	l1->p = 2 * l1->dy - l1->dx;
	while (l1->x < l1->x1)
	{
		if (l1->p >= 0)
		{
			mlx_pixel_put(w1->mlx, w1->win, l1->x, l1->y, 0xFFFFFF);
			if (c == '+')
				l1->y = l1->y + 1;
			if (c == '-')
				l1->y = l1->y - 1;
			l1->p = l1->p + 2 * l1->dy - 2 * l1->dx;
		}
		else
		{
			mlx_pixel_put(w1->mlx, w1->win, l1->x, l1->y, 0xFFFFFF);
			l1->p = l1->p + 2 * l1->dy;
		}
		l1->x = l1->x + 1;
	}
}

void	ft_line(t_line *l1, void *param)
{
	int swp;
	l1->dx = l1->x1 - l1->x0;
	l1->dy = l1->y1 - l1->y0;

	if (l1->dx < 0)
	{
		swp = l1->x0;
		l1->x0 = l1->x1;
		l1->x1 = swp;
		swp = l1->y0;
		l1->y0 = l1->y1;
		l1->y1 = swp;
	}
	l1->dx = l1->x1 - l1->x0;
	l1->dy = l1->y1 - l1->y0;
	
	if (l1->dy >= 0)
		right(l1, param, '+');
	if (l1->dy < 0)
		right(l1, param, '-');
}
