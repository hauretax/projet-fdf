/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:49:01 by hutricot          #+#    #+#             */
/*   Updated: 2019/02/05 15:46:29 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "h.h"
#include <unistd.h>

void	right_down(t_line *l1, t_ptr *w1)
{
	l1->x = l1->x0;
	l1->y = l1->y0;
	l1->dy = (l1->dy > 0) ? l1->dy : l1->dy * -1;
	l1->dx = (l1->dx > 0) ? l1->dx : l1->dy * -1;
	l1->p = 2 * l1->dy - l1->dx;
	while (l1->x < l1->x1)
	{
		if (l1->p >= 0)
		{
			w1->str[l1->y * WIDTH + l1->x] = 0xFF0000;
			l1->y = l1->y + 1;
			l1->p = l1->p + 2 * l1->dy - 2 * l1->dx;
		}
		else
		{
			w1->str[l1->y * WIDTH + l1->x] = 0xFF0000;
			l1->p = l1->p + 2 * l1->dy;
		}
		l1->x = l1->x + 1;
	}
}

void	right_down2(t_line *l1, t_ptr *w1)
{
	l1->x = l1->x0;
	l1->y = l1->y0;
	l1->dy = (l1->dy > 0) ? l1->dy : l1->dy * -1;
	l1->dx = (l1->dx > 0) ? l1->dx : l1->dy * -1;
	l1->p = 2 * l1->dx - l1->dy;
	while (l1->y < l1->y1)
	{
		if (l1->p >= 0)
		{
			w1->str[l1->y * WIDTH + l1->x] = 0xFF0000;
			l1->x = l1->x + 1;
			l1->p = l1->p + 2 * l1->dx - 2 * l1->dy;
		}
		else
		{
			w1->str[l1->y * WIDTH + l1->x] = 0xFF0000;
			l1->p = l1->p + 2 * l1->dx;
		}
		l1->y = l1->y + 1;
	}
}

void	right_up(t_line *l1, t_ptr *w1)
{
	l1->x = l1->x0;
	l1->y = l1->y0;
	l1->dy = (l1->dy > 0) ? l1->dy : l1->dy * -1;
	l1->dx = (l1->dx > 0) ? l1->dx : l1->dy * -1;
	l1->p = 2 * l1->dy - l1->dx;
	while (l1->x < l1->x1)
	{
		if (l1->p >= 0)
		{
			w1->str[l1->y * WIDTH + l1->x] = 0xFF0000;
			l1->y = l1->y - 1;
			l1->p = l1->p + 2 * l1->dy - 2 * l1->dx;
		}
		else
		{
			w1->str[l1->y * WIDTH + l1->x] = 0xFF0000;
			l1->p = l1->p + 2 * l1->dy;
		}
		l1->x = l1->x + 1;
	}
}

void	right_up2(t_line *l1, t_ptr *w1)
{
	l1->x = l1->x0;
	l1->y = l1->y0;
	l1->dy = (l1->dy > 0) ? l1->dy : l1->dy * -1;
	l1->dx = (l1->dx > 0) ? l1->dx : l1->dy * -1;
	l1->p = 2 * l1->dx - l1->dy;
	while (l1->y > l1->y1)
	{
		if (l1->p >= 0)
		{
			w1->str[l1->y * WIDTH + l1->x] = 0xFF0000;
			l1->x = l1->x + 1;
			l1->p = l1->p + 2 * l1->dx - 2 * l1->dy;
		}
		else
		{
			w1->str[l1->y * WIDTH + l1->x] = 0xFF0000;
			l1->p = l1->p + 2 * l1->dx;
		}
		l1->y = l1->y - 1;
	}
}

void	ft_line(t_line l1, void *param)
{
	if (l1.x1 - l1.x0 < 0)
	{
		ft_swap(&(l1.x0), &(l1.x1));
		ft_swap(&(l1.y0), &(l1.y1));
	}
	l1.dx = l1.x1 - l1.x0;
	l1.dy = l1.y1 - l1.y0;
	if (l1.dy >= 0)
	{
		if (l1.dy > l1.dx)
			right_down2(&l1, param);
		else
			right_down(&l1, param);
	}
	if (l1.dy < 0)
	{
		if (ABS(l1.dy) > l1.dx)
			right_up2(&l1, param);
		else
			right_up(&l1, param);
	}
}
