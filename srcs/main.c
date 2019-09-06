/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 13:53:48 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/06 17:24:38 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		ft_mapinitial(t_map *map)
{
	map->rooms = NULL;
	map->new_room = NULL;
	map->edge_table= NULL;
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
	t_map		map;

	(void)argc;
	(void)argv;
	ft_mapinitial(&map);
	ft_validation(&map);
	exit (-1);
	return (0);
}
