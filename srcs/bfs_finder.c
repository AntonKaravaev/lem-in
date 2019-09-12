/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_finder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:35:11 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/12 23:12:32 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void 	ft_find_bfs(t_map *map)
{
	int i;
	int q;
	int z;

	i = -1;
	if (!(map->bfs_str = (int *)malloc(sizeof(int) * (map->ls_counter))))
		exit(-1);
	while (++i < map->ls_counter)
		map->bfs_str[i] = -1;
	map->bfs_str[0] = 0;
	map->bfs_str[map->ls_counter - 1] = 1;
	z = map->ls_counter - 1;
	q = 0;
	while (z > 0)
	{
		q = -1;
		while (map->ways[z][0] && map->ways[z - 1][++q] != -1)
		{
 			if (map->edge_table[map->ways[z][0]][map->ways[z -1][q]] == 1)
			{
				map->bfs_str[z - 1] = map->ways[z - 1][q];
				break ;
			}
		}
		z--;
	}
	i = 0;
	//ft_printf("Thats a right way\n");
	// while (i < map->ls_counter - 1)
	// {
	// 	ft_printf("%s ", map->str[map->bfs_str[i]]);
	// 	i++;
	// }
	// ft_printf("%s\n", map->str[map->bfs_str[i]]);
	// ft_printf("\n");
}
