/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 13:53:48 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/26 13:45:50 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// void			ft_free_whats_needs(t_map *map)
// {
// 	ft_str2del(&map->str);
// 	ft_intstrdel(&map->temp_line);
// 	ft_intstr2del(&map->edge_table, map->q_rooms);
// 	// как зафришить список.
// }

static void		ft_mapinitial(t_map *map)
{
	map->temp_line = NULL;
	map->rooms = NULL;
	map->new_room = NULL;
	map->edge_table = NULL;
	map->str = NULL;
	map->q_rooms = 0;
	map->ants = 0;
	map->s = 0;
	map->e = 0;
	map->lf = 0;
	map->sf = 0;
	map->ef = 0;
	map->temp_x = 0;
	map->temp_y = 0;
	map->max_x = 0;
	map->max_y = 0;
}

int				main(int argc, char *argv[])
{
	t_map	map;
	t_farm	farm;

	(void)argc;
	(void)argv;
	ft_mapinitial(&map);
	ft_farm_initial(&farm, &map);
	ft_validation(&map, &farm);
	if (map.ants != 0 && map.s != 0 && map.e != 0 && map.q_rooms != 0
		&& map.sf != 0 && map.ef != 0 && map.lf != 0)
		ft_solution(&map, &farm);
	else
		ft_input_error();
	//ft_free_whats_needs(&map);
	return (0);
}
