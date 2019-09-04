/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoilemin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 13:18:41 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/04 15:57:02 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		ft_error_atoilemin(char *str, char *str_error)
{
	ft_putstr_fd(str_error, 2);
	ft_putstr_fd(str, 2);
	ft_putchar('\n');
	exit(-1);
}

static void		ft_atoisuplem(char *s, long n, char c, char *str_error)
{
	if (n > 2147483647 || n < 1 || (c - '0' < 0 || c - '0' > 9))
		ft_error_atoilemin(s, str_error);
}

int				ft_atoilemin(const char *s)
{
	long	n;
	int		i;

	n = 0;
	i = 0;
	if (s && *s)
	{
		if (s[i] == '+')
			i++;
		if (s[i] < '1' || s[i] > '9')
			ft_error_atoilemin((char *)s, "Error! (atoilemin) = ");
		else
			n = s[i++] - '0';
		while (s[i] >= '0' && s[i] <= '9')
		{
			n = (n * 10) + (s[i] - '0');
			ft_atoisuplem((char *)s, n, s[i++], "Error! (atoilemin) = ");
		}
		if (s[i] != '\0')
			ft_error_atoilemin((char *)s, "Error! (atoilemin) = ");
		return ((int)n);
	}
	ft_error_atoilemin((char *)s, "Error! (atoilemin) = ");
	return (0);
}

void			ft_atoicoor(const char *s)
{
	long	n;
	int		i;

	n = 0;
	i = 0;
	if (s && *s)
	{
		if (s[i] == '+')
			i++;
		if (s[i] == '0' && !s[i + 1])
			return ;
		if (s[i] < '1' || s[i] > '9')
			ft_error_atoilemin((char *)s, "Error! (coor_of_room) = ");
		else
			n = s[i++] - '0';
		while (s[i] >= '0' && s[i] <= '9')
		{
			n = (n * 10) + (s[i] - '0');
			ft_atoisuplem((char *)s, n, s[i++], "Error! (coor_of_room) = ");
		}
		if (s[i] != '\0')
			ft_error_atoilemin((char *)s, "Error! (coor_of_room) = ");
		return ;
	}
	ft_error_atoilemin((char *)s, "Error! (coor_of_room) = ");
}
