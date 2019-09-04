/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 13:53:48 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/04 18:13:54 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// static	void	ft_roominitial(t_room *new_room)
// {
// 	new_room->name = NULL;
// 	new_room->x = 0;
// 	new_room->y = 0;
// }

static void		ft_mapinitial(t_map *map)
{
	map->rooms = NULL;
	map->edge_table= NULL;
	map->str = NULL;
	map->q_rooms = 0;
	map->ants = 0;
	map->s = 0;
	map->e = 0;
	map->ants_in_start = 0;
	map->ants_in_end = 0;
	map->max_x = 0;
	map->max_y = 0;
}

// static void		ft_rooms(t_list rooms)
// {
// 	if (!(rooms = (t_list *)malloc(sizeof(t_list)))
// 		exit (-1);
// }

int				main(int argc, char *argv[])
{
	//t_list		rooms;
	t_map		map;

	(void)argc;
	(void)argv;
	//(void)rooms;
	ft_mapinitial(&map);
//	ft_roominitial(&rooms);
	ft_validation(&map);

	return (0);
}
