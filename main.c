/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:23:14 by hutricot          #+#    #+#             */
/*   Updated: 2019/01/18 19:18:16 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		**creat_tab(t_list *lst)
{
	t_list	*tmp;
	int		i;
	
	i = 0;
	tmp = lst;
	while (tmp->next != NULL)
	{
		printf("%s",tmp->content);
		i++;
		tmp = tmp->next;
	}
	printf("%d",i);
	

}

t_list	*creat_lst(char *str)
{
	int		fd;
	char	*line;
	t_list	*l[2];

	line = NULL;
	fd = open(str, O_RDONLY);
	ft_get_line(fd, &line);
	l[0] = ft_lstnew(line, (ft_strlen(line) + 1));
	free(line);
	line = NULL;
	while(ft_get_line(fd, &line))
	{
		l[1] = ft_lstnew(line, (ft_strlen(line) + 1));
		ft_lstadd_b(&l[0], l[1]);
		free(line);
		line = NULL;
	}
	close (fd);
	return(l[0]);
}

int 		main(int c, char **v)
{
	t_list	*lst;
	int		**tab;

	if (c != 2)
		return (ft_error(0));
	lst = creat_lst(v[1]);
	tab = creat_tab(lst);
	return (0);
}
