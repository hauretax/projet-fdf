/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_dot_h.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:00:24 by psim              #+#    #+#             */
/*   Updated: 2019/01/18 18:24:13 by psim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HEADER_DOT_H_H
# define HEADER_DOT_H_H
# include <stdlib.h>

typedef struct	s_param
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*data;
}				t_param;

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

void			ft_line(t_line *l1, void *param);

#endif
