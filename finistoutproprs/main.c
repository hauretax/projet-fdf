/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:23:14 by hutricot          #+#    #+#             */
/*   Updated: 2019/02/05 19:00:01 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static int		cmp_num(char *str)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			n++;
			while (str[i] == ' ')
				i++;
		}
		i++;
	}
	n++;
	return (n);
}

static int		*feed_tab(int max, char *str)
{
	int i;
	int *tab;

	if ((tab = (int *)malloc(sizeof(int *) * max)) == 0)
		exit(0);
	i = 0;
	while (i < max)
	{
		tab[i] = ft_atoi(str);
		str++;
		i++;
		while ((*str >= '0' && *str <= '9') || *str == '-')
			str++;
		while (*str == ' ')
			str++;
	}
	return (tab);
}

static int		**creat_tab(t_list *lst)
{
	int		i[4];
	int		**tab;

	i[0] = 0;
	i[2] = cmp_num((char *)lst->content);
	if ((tab = (int **)malloc(sizeof(int *) * (ft_lstsize(lst) + 1))) == 0)
		exit(0);
	while (lst != NULL)
	{
		tab[i[0]] = feed_tab(i[2], (char *)lst->content);
		i[0]++;
		lst = lst->next;
	}
	tab[i[0]] = NULL;
	return (tab);
}

static t_list	*creat_lst(char *str)
{
	int		fd;
	char	*line;
	t_list	*l[2];

	line = NULL;
	fd = open(str, O_RDONLY);
	if ((ft_get_line(fd, &line)) == -1)
		exit(0);
	l[0] = ft_lstnew(line, (ft_strlen(line) + 1));
	free(line);
	line = NULL;
	while (ft_get_line(fd, &line))
	{
		l[1] = ft_lstnew(line, (ft_strlen(line) + 1));
		ft_lstadd_b(&l[0], l[1]);
		free(line);
		line = NULL;
	}
	close(fd);
	return (l[0]);
}

int				main(int c, char **v)
{
	t_list	*lst;
	int		**tab;
	int		t[2];

	if (c != 2)
		return (ft_error(0));
	lst = creat_lst(v[1]);
	tab = creat_tab(lst);
	t[0] = (ft_lstsize(lst) + 1);
	t[1] = (cmp_num((char *)lst->content) - 1);
	ft_freelst(&lst);
	ft_window(tab, t);
	return (0);
}