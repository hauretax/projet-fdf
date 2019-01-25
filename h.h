/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:22:33 by hutricot          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/01/25 17:55:08 by psim             ###   ########.fr       */
=======
/*   Updated: 2019/01/25 16:18:02 by hutricot         ###   ########.fr       */
>>>>>>> e144bcda00fd57a6fac19c12c1dded5ce591c83b
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
	int		key;
	int		x;
	int		y;
	int		bpp;
	int		s_l;
	int		v;
	int		**tab[2];
	int		origine[2];
	int		iso[3][2];
}				t_ptr;

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
void			ft_display(int **tab, int t[2], t_ptr);

#endif
