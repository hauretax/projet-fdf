/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:43:40 by hutricot          #+#    #+#             */
/*   Updated: 2019/01/29 13:11:04 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

static int	deal_key(int key, t_ptr *ptr)
{
	mlx_clear_window(ptr->mlx, ptr->win);
	if (key == 88)
		ptr->o[X] += 10;
	if (key == 86)
		ptr->o[X] -= 10;
	if (key == 91)
		ptr->o[Y] -= 10;
	if (key == 84)
		ptr->o[Y] += 10;
	ft_display(ptr->tab, ptr->t, *ptr);
	return (key);
}

int			ft_window(int **tab, int t[2])
{
	t_ptr ptr;

	ptr.x = 0;
	ptr.y = 0;
	ptr.t[X] = t[X];
	ptr.t[Y] = t[Y];
	ptr.tab = tab;
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, 2000, 1500, "mlx 42");
	ft_iso(&ptr);
	ft_display(tab, t, ptr);
	mlx_key_hook(ptr.win, deal_key, (void *)&ptr);
	mlx_loop(ptr.mlx);
	return (2);
}
