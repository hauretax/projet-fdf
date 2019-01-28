/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:43:40 by hutricot          #+#    #+#             */
/*   Updated: 2019/01/28 13:02:31 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

static int	deal_key(int key, t_ptr *ptr)
{
	printf("%d\n", key);
	printf("%d\n",ptr->origine[X]);
	return (key);
}
/*
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
*/
int			ft_window(int **tab, int t[2])
{
	t_ptr ptr;

	ptr.x = 0;
	ptr.y = 0;
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, 2000, 1500, "mlx 42");
	ft_iso(&ptr);
	//mlx_put_image_to_window (ptr.mlx, ptr.win, ptr.img, 300, 300);
	ft_display(tab, t, ptr);
	mlx_key_hook(ptr.win, deal_key, (void *)&ptr);
	mlx_loop(ptr.mlx);
	return (2);
}
