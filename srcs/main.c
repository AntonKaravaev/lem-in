/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 13:53:48 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/17 06:54:39 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_free_whats_needs(t_map *map)
{
	ft_intstrdel(&map->bfs_str);
	ft_str2del(&map->str);
	ft_intstrdel(&map->temp_line);
	ft_intstr2del(&map->ways, map->ls_counter);
	ft_intstr2del(&map->edge_table, map->q_rooms);
	// как зафришить список.
}

static void	ft_mapinitial(t_map *map)
{
	map->ways = NULL;
	map->temp_line = NULL;
	map->rooms = NULL;
	map->goodways = NULL;
	map->n_g = NULL;	
	map->new_room = NULL;
	map->edge_table = NULL;
	map->expand_et = NULL;
	map->et_wc = NULL;
	map->str = NULL;
	map->q_rooms = 0;
	map->real_rooms = 0;
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
	map->ls_counter = 0;
	map->bfs = 0;
	map->ways_to_go = 0;
	map->bfs_str = NULL;
	map->pl_dup = NULL;
}

int			main(int argc, char *argv[])
{
	t_map		map;
	
	(void)argc;
	(void)argv;
	ft_mapinitial(&map);
	ft_validation(&map);
	if (map.ants != 0 && map.s != 0 && map.e != 0 && map.q_rooms != 0 && map.sf != 0 && map.ef != 0 && map.lf != 0)
		ft_solution(&map);
	else
	{
		// ft_printf("map.ants = %d\n", map.ants);
		// ft_printf("map.s = %d\n", map.s);
		// ft_printf("map.e = %d\n", map.e);
		// ft_printf("map.q_rooms = %d\n", map.q_rooms);
		// ft_printf("map.sf = %d\n", map.sf);
		// ft_printf("map.ef = %d\n", map.ef);
		// ft_printf("map.lf = %d\n", map.lf);
		ft_input_error();
	}
		
	ft_free_whats_needs(&map);
	return (0);
}
