/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:43:40 by hutricot          #+#    #+#             */
/*   Updated: 2019/01/15 16:36:36 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

int 	deal_key(int key, void *param)
{
	write(1, "X", 1);
	return (key);
}

int main()
{
	t_ptr ptr;

	ptr.x = 0;
	ptr.y = 0;
	ptr.mlx = mlx_init();
	ptr.img = mlx_new_image (ptr.mlx, 300, 300);	
	ptr.str = (int *)mlx_get_data_addr(ptr.img, &(ptr.bpp), &(ptr.s_l), &(ptr.v));
	ptr.win = mlx_new_window(ptr.mlx, WINDOW, "test 1");
	while (ptr.x < 90000)
	{
		ptr.str[ptr.x] = 0xF12AB2;
		ptr.x++;
	}
	ptr.str[3015] = 0xFFFFFF;
	ptr.str[15*300+10] = 0xFFFFFF;
	mlx_put_image_to_window (ptr.mlx, ptr.win, ptr.img, 0, 0);
	mlx_put_image_to_window (ptr.mlx, ptr.win, ptr.img, 300, 300);
	mlx_key_hook(ptr.win, deal_key,(void*)0);
	mlx_loop(ptr.mlx);
}
