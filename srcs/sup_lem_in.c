/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sup_lem_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:43:54 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/08 13:44:02 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_printlinkstable(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	ft_printf("    0 1 2 3 4 5\n");
	ft_printf("   _____________\n");
	while (i < map->q_rooms)
	{
		j = 0;
		ft_printf("%d  |", i);
		while (j < map->q_rooms)
		{
			ft_printf("%d|", map->edge_table[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("   -------------\n");
}
