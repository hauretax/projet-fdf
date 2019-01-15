/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:22:33 by hutricot          #+#    #+#             */
/*   Updated: 2019/01/15 16:36:41 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_H
# define H_H
# define WINDOW 2500, 1300 
# include <unistd.h>
# include "mlx.h"

typedef struct	s_list
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
}	t_ptr;

#endif
