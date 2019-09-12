/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sup_lem_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:43:54 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/12 21:36:44 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_printlinkstable(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	ft_printf("    0 1 2 3 4 5 6 7 8\n");
	ft_printf("   __________________\n");
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
	ft_printf("   ------------------\n");
}

void		ft_print_BFS(t_map *map)
{
	int		i;
	int		j;

	i = -1;
	ft_printf("|0| |1| |2|  |3|  |4| |5|\n");
	while (++i < map->ls_counter)
	{
		j = -1;
		while (map->ways[i][++j] != -1)
		{
			ft_printf("|%d| ", map->ways[i][j]);
		}
		ft_printf("|%d|", map->ways[i][j]);
		ft_printf("\n");
	}
	ft_printf("\n");
}