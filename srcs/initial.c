/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 12:43:47 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/26 13:43:47 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_farm_initial(t_farm *farm, t_map *map)
{
	farm->count_room = map->q_rooms;
	farm->array_room = NULL;
	farm->ways_line = NULL; // BFS potensial ways
	farm->bfs = NULL; // current good bfs
	farm->bfs_flag = 0;
	farm->mpw = 0;
	farm->levels_of_ways_line = 0;
	farm->p = -1;
}
