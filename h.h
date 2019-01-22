/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:22:33 by hutricot          #+#    #+#             */
/*   Updated: 2019/01/22 13:22:26 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_H
# define H_H
# define WINDOW 2500, 1300
# include <unistd.h>
# include "libft/libft.h"
# include "mlx.h"

typedef struct	s_fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*str;
	int		key;
	int		x;
	int		y;
	int		bpp;
	int		s_l;
	int		v;
}				t_ptr;

typedef struct	s_line
{
	int x0;
	int y0;
	int x1;
	int y1;
	int y;
	int x;
	int dx;
	int dy;
	int p;
}				t_line;

int				ft_error(int e);
int				ft_window(int **tab, int t[2]);
void			ft_line(t_line *l1, void *param);

#endif
