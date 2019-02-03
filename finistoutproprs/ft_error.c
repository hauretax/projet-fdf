/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:24:57 by hutricot          #+#    #+#             */
/*   Updated: 2019/01/17 13:48:30 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

int	ft_error(int e)
{
	if (e == 0)
	{
		write(2, "usage: ./fdf source_file\n", 25);
		return (0);
	}
	return (0);
}
