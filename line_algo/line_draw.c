/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:49:25 by psim              #+#    #+#             */
/*   Updated: 2019/01/18 18:24:29 by psim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "header_dot_h.h"
#include <unistd.h>

void	ft_line(t_line *l1, void *param)
{
	t_param *w1;

	w1 = (t_param *)param;
	l1->dx = l1->x1 - l1->x0;
	l1->dy = l1->y1 - l1->y0;
	l1->x = l1->x0;
	l1->y = l1->y0;
	l1->p = 2 * l1->dy - l1->dx;
	while (l1->x < l1->x1)
	{
		if (l1->p >= 0)
		{
			mlx_pixel_put(w1->mlx_ptr, w1->win_ptr, l1->x, l1->y, 0xFFFFFF);
			l1->y = l1->y + 1;
			l1->p = l1->p + 2 * l1->dy - 2 * l1->dx;
		}
		else
		{
			mlx_pixel_put(w1->mlx_ptr, w1->win_ptr, l1->x, l1->y, 0xFFFFFF);
			l1->p = l1->p + 2 * l1->dy;
		}
		l1->x = l1->x + 1;
	}
}
