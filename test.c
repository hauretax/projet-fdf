/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:43:40 by hutricot          #+#    #+#             */
/*   Updated: 2019/01/22 13:34:51 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

static int	deal_key(int key, void *param)
{
	write(1, "X", 1);
	return (key);
}

void	ft_trwho(int **tab, int t[2], t_ptr ptr)
{
	t_line l;
	int		s;

	l.x1 = 0;
	l.y1= 0;
	l.x0 = 0;
	l.y0 = 10;
	while (t[0])
	{
	ft_line(&l, &ptr);
		s = t[1];
		while (s)
		{
	ft_line(&l, &ptr);
			l.x1 += 10;
			l.x0 += 10;
			s--;
		}
		l.y1 += 10;
		l.y0 += 10;
		l.x1 = 0;
		l.x0 = 10;
		t[0]--;
	}
}

void	ft_image(t_ptr *p, int **tab, int t[2])
{
	int i[2];

	i[0] = 0;
	i[1] = 0;
	p->img = mlx_new_image (p->mlx, 1250, 650);	
	p->str = (int *)mlx_get_data_addr(p->img, &(p->bpp), &(p->s_l), &(p->v));
	p->win = mlx_new_window(p->mlx, WINDOW, "test 1");
	while (p->y < t[0])
	{
		p->x = 0;
		while (p->x < t[1])
		{
			p->str[(p->y * 10 + i[0])*1250+(p->x * 20 + i[1])] = 0xFFFFFF;
			p->x++;
		}
		i[1] += 5;
		p->y++;
	}
}

int			ft_window(int **tab, int t[2])
{
	t_ptr ptr;

	ptr.x = 0;
	ptr.y = 0;
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, 2000, 1500, "mlx 42");
	//ft_image(&ptr, tab, t);
	//mlx_put_image_to_window (ptr.mlx, ptr.win, ptr.img, 300, 300);
	ft_trwho(tab, t, ptr);
	//mlx_key_hook(ptr.win, deal_key,(void*)0);
	mlx_loop(ptr.mlx);
	return (2);
}
