/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 10:19:27 by hutricot          #+#    #+#             */
/*   Updated: 2019/01/29 13:04:04 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

static void	ft_compute_line(t_ptr ptr, t_point *p, int h[2], int axis)
{
	t_line l;

	if (axis == 0)
		p->y += ptr.iso[0][1];
	if (axis == 0)
		p->x += ptr.iso[0][0];
	l.x1 = p->x;
	l.y1 = p->y - h[0] * ptr.iso[2][0];
	l.x0 = p->x + ptr.iso[axis][0];
	l.y0 = p->y + ptr.iso[axis][1] - h[1] * ptr.iso[2][0];
	ft_line(l, &ptr);
}

void		ft_display(int **tab, int t[2], t_ptr ptr)
{
	int		i[2];
	t_point	p;
	int		h[2];

	i[Y] = 0;
	while (i[Y] + 1 < t[0])
	{
		p.x = ptr.o[X] + i[Y] * ptr.iso[1][0];
		p.y = ptr.o[Y] + i[Y] * ptr.iso[1][1];
		i[X] = 0;
		while (i[X]  <= t[1])
	 	{
			h[0] = tab[i[Y]][i[X]];
			if (i[X] < t[1] - 1)
				h[1] = tab[i[Y]][i[X] + 1];
			else
				h[1] = h[0];
			if (i[X] <= t[1])
				ft_compute_line(ptr, &p, h, 0);
			if (i[Y] + 2 < t[0])
				h[1] = tab[i[Y] + 1][i[X]];
			if (i[Y] + 2 < t[0])
				ft_compute_line(ptr, &p, h, 1);
			i[X]++;
		}
		i[Y]++;
	}
}
