/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_finder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:35:11 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/17 04:48:00 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void 	ft_find_bfs(t_map *map)
{
	int i;
	int p;
	int z;

	i = -1;
	if (map->bfs_str != NULL)
		ft_intstrdel(&map->bfs_str);
	if (!(map->bfs_str = (int *)malloc(sizeof(int) * (map->ls_counter + 1))))
		exit(-1);
	while (++i < map->ls_counter)
	{
		map->bfs_str[i] = -1;
	}
		
	map->bfs_str[i] = -1;
	map->bfs_str[0] = 0;
	map->bfs_str[map->ls_counter - 1] = 1;
	z = map->ls_counter - 1;
	p = 0;
	//ft_et_wc(map);
	ft_printlinkstable(map);
	while (z > 0)
	{
		p = 0;
		while (p < map->q_rooms && map->ways[z][0] && map->ways[z - 1][p] != -1)
		{
			ft_printf("map->ways[%d][0] = %d\n", z,  map->ways[z][0]);
			ft_printf("map->ways[%d][%d] = %d\n", z - 1, p, map->ways[z - 1][p]);
 			if (map->edge_table[map->ways[z - 1][p]][map->ways[z][0]] == 1)
			{
				ft_printf("HEllo \n");
				map->bfs_str[z - 1] = map->ways[z - 1][p];
				map->ways[z - 1][0] = map->ways[z - 1][p];
				break ;
			}
			p++;
		}
		z--;
	}
	i = 0;
	ft_printf("Thats a right way\n");
	while (i < map->ls_counter - 1)
	{
		ft_printf("%d ", map->bfs_str[i]);
		i++;
	}
	ft_printf("%d\n", map->bfs_str[i]);
	ft_printf("\n");
}
