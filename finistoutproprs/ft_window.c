/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:43:40 by hutricot          #+#    #+#             */
/*   Updated: 2019/02/05 15:59:21 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

static void	freexit(t_ptr *ptr)
{
	int i;

	i = 0;
	while ((ptr->tab)[i])
	{
		free((ptr->tab)[i]);
		i++;
	}
	free(ptr->tab);
	exit(0);
}

static void	ft_m_f(t_ptr *ptr, int key)
{
	if (key == 78)
	{
		ptr->iso[1][1]--;
		ptr->iso[0][0]--;
	}
	if (key == 69)
	{
		ptr->iso[1][1]++;
		ptr->iso[0][0]++;
	}
	if (key == 89)
		ptr->iso[2][0]--;
	if (key == 92)
		ptr->iso[2][0]++;
}

static void	ft_m_fonction(t_ptr *ptr, int key)
{
	if (ptr->iso[2][0] == 0)
		ptr->iso[2][0] = 1;
	if (key == 124)
		ptr->iso[0][1]++;
	if (key == 126)
		ptr->iso[1][0]++;
	if (key == 123)
		ptr->iso[0][1]--;
	if (key == 125)
		ptr->iso[1][0]--;
}

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
	ft_m_fonction(ptr, key);
	ft_m_f(ptr, key);
	if (key == 53)
		freexit(ptr);
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
	ptr.win = mlx_new_window(ptr.mlx, WIDTH, HEIGHT, "mlx 42");
	ft_iso(&ptr);
	ft_display(tab, t, ptr);
	mlx_key_hook(ptr.win, deal_key, (void *)&ptr);
	mlx_loop(ptr.mlx);
	return (2);
}
