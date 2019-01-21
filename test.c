/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:43:40 by hutricot          #+#    #+#             */
/*   Updated: 2019/01/21 15:57:24 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

static int	deal_key(int key, void *param)
{
	write(1, "X", 1);
	return (key);
}

void	ft_image(t_ptr *p, int **tab, int t[2])
{
	p->img = mlx_new_image (p->mlx, 1250, 650);	
	p->str = (int *)mlx_get_data_addr(p->img, &(p->bpp), &(p->s_l), &(p->v));
	p->win = mlx_new_window(p->mlx, WINDOW, "test 1");
	while (p->y < t[0])
	{
		p->x = 0;
		while (p->x < t[1])
		{
			p->str[(p->y * 20)*1250+(p->x * 20)] = 0xFFFFFF;
			p->x++;
		}
		p->y++;
	}
}

int			ft_window(int **tab, int t[2])
{
	t_ptr ptr;

	ptr.x = 0;
	ptr.y = 0;
	ptr.mlx = mlx_init();
	ft_image(&ptr, tab, t);
	mlx_put_image_to_window (ptr.mlx, ptr.win, ptr.img, 300, 300);
	mlx_key_hook(ptr.win, deal_key,(void*)0);
	mlx_loop(ptr.mlx);
	return (2);
}
