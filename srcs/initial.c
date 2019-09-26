/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 12:43:47 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/26 23:45:47 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_farm_initial(t_farm *farm, t_map *map)
{
	farm->cnt = map->q_rooms;
	farm->arr = NULL;
	farm->wl = NULL; // BFS potensial ways
	farm->bfs = NULL; // current good bfs
	farm->bfs_flag = 0;
	farm->mpw = 0;
	farm->lwl = 0;
	farm->p = -1;
}
