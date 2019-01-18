/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutricot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:03:36 by hutricot          #+#    #+#             */
/*   Updated: 2018/11/14 13:00:05 by hutricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	long long int	nb;
	int				i;
	long long int	n;

	i = 0;
	n = 1;
	nb = 0;
	while (str[i] == 9 || str[i] == 32 || str[i] == 12 || str[i] == 13 ||
			str[i] == 10 || str[i] == 11)
		i++;
	if (str[i] == '-')
		n = -1;
	if (str[i] == '-')
		i++;
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < 48 || 57 < str[i])
			return (nb * n);
		else
			nb = (nb * 10) + (long long int)(str[i] - '0');
		i++;
	}
	return (nb * n);
}
