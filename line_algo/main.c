/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:39:08 by psim              #+#    #+#             */
/*   Updated: 2019/01/18 18:25:55 by psim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "header_dot_h.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	deal_key(int key, void *param)
{
	t_param *win1;

	if (param == 0)
		return (0);
	win1 = (t_param *)param;
	puts(win1->data);
	return (0);
}

int		main(void)
{
	t_param win1[1];
	t_line		line[1];
	line->x0 = 10;
	line->y0 = 200;
	line->x1 = 200;
	line->y1 = 250;

	win1->data = "couco\n";
	win1->mlx_ptr = mlx_init();
	win1->win_ptr = mlx_new_window(win1->mlx_ptr, 500, 500, "mlx 42");
	ft_line(line, win1);
	mlx_pixel_put(win1->mlx_ptr, win1->win_ptr, 10, 200, 0x00FFFF);
	mlx_pixel_put(win1->mlx_ptr, win1->win_ptr, 200, 250, 0x00FFFF);
	mlx_key_hook(win1->win_ptr, deal_key, win1);
	mlx_loop(win1->mlx_ptr);
}
