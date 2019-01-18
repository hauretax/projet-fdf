/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:23:14 by hutricot          #+#    #+#             */
/*   Updated: 2019/01/18 17:39:45 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "h.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

t_list	*creat_lst(char *str)
{
	int		fd;
	char	*line;
	t_list	*l[2];

	line = NULL;
	fd = open(str, O_RDONLY);
	ft_get_line(fd, &line)
	l[0] = ft_lstnew(line, ft_strlen(line));
	free(line);
	line = NULL;
	while(ft_get_line(fd, &line))
	{
		l[1] = ft_lstnew(line, ft_strlen(line));
		ft_lstadd_b(l[0], l[1]);
		printf("%s",line);
		free(line);
		line = NULL;
	}
	close (fd);
}

int 		main(int c, char **v)
{
	t_list
	if (c != 2)
		return (ft_error(0));
	creat_lst(v[1]);
	return (0);
}
