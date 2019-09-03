/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoilemin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 13:18:41 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/03 15:09:47 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		ft_errorants()
{
	write(2, "Error(ants)\n", 12);
	exit(-1);
}

static void		ft_atoisuplem(long n, char c)
{
	if (n > 2147483647 || n < 1 || (c - '0' < 0 || c - '0' > 9))
		ft_errorants();
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
			ft_errorants();
		else
			n = s[i++] - '0';
		while (s[i] >= '0' && s[i] <= '9')
		{
			n = (n * 10) + (s[i] - '0');
			ft_atoisuplem(n, s[i++]);
		}
		if (s[i] != '\0')
			ft_errorants();
		return ((int)n);
	}
	ft_errorants();
	return (0);
}
