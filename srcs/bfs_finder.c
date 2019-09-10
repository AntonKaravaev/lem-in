/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_finder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:35:11 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/10 23:50:47 by crenly-b         ###   ########.fr       */
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
	i = 1;
	z = 0;
	q = 0;
	while (i < map->ls_counter)
	{
		q = -1;
		while (map->ways[z][0] != -1 && map->ways[z + 1][++q] != -1)
		{
 			if (map->edge_table[map->ways[z][0]][map->ways[z + 1][q]] == 1)
			{
				map->bfs_str[i++] = map->ways[z + 1][0];
				break ;
			}
		}
		z++;
	}
	i = 0;
	while (i < map->ls_counter)
	{
		printf("%d ", map->bfs_str[i]);
		i++;
	}
}
