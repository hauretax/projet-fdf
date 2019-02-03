/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:22:33 by hutricot          #+#    #+#             */
/*   Updated: 2019/02/03 11:41:01 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_H
# define H_H
# define WINDOW 2500, 1300
# define X 0
# define Y 1
# include <unistd.h>
# include "libft/libft.h"
# include "mlx.h"
# define ABS(x) (x > 0 ? x : -x)

typedef struct	s_fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*str;
	int		t[2];
	int		x;
	int		y;
	int		bpp;
	int		s_l;
	int		v;
	int		**tab;
	int		o[2];
	int		iso[3][2];
}				t_ptr;

typedef struct	s_rgb
{
	int red;
	int green;
	int blue;
}				t_rgb;

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

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

void			ft_iso(t_ptr *ptr);
void			ft_swap(int *a, int *b);
int				ft_error(int e);
int				ft_window(int **tab, int t[2]);
void			ft_line(t_line l1, void *param);
void			ft_display(int **tab, int t[2], t_ptr ptr);

#endif
