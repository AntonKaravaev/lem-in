/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:06:44 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/03 22:54:49 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_solution(t_map *map, t_farm *farm)
{
	t_path *answer;
	t_farm split;
	t_farm pfarm;

	ft_str_of_names(map);
	farm->cnt = map->q_rooms;
	ft_farm_initial(&split, map);
	init_split(farm, &split);//olya
	ft_create_ways_lines(&split); // helper of BFS
	ft_create_line(&split);
	ft_bfs(split.arr, split.cnt, &split);
	ft_dup_clear_farm(&pfarm, farm->cnt);//olya
	if (split.bfs_flag == 0)
		ft_cant_find_way_error();
	else if (split.mpw == 1 || map->ants == 1)
	{
		ft_print_way1(map, &split);
		return ; 
	}
	answer = ft_suurballe(farm, &split, &pfarm, map->ants);
	//olya_write_name_path(answer, farm->cgp, farm);
	ft_print_result(answer, map, farm->cgp, map->ants);
}
