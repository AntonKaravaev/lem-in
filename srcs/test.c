/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:13:51 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/13 18:57:09 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			ft_create_expand_et(t_map *map)
{
	int i;

	i = -1;
	if (!(map->expand_et = (int *)malloc(sizeof(int) * map->q_rooms)))
	 		exit(-1);
	while (++i < map->q_rooms)
		map->expand_et[i] = -1;
}

void	ft_create_linkstable_of_size(t_map *map, int size)
{
	int		i;
	int		j;

	i = 0;
    if (map->edge_table != NULL)
		ft_intstr2del(&map->edge_table, map->q_rooms);
	if (!(map->edge_table = (int **)malloc(sizeof(int *) * size)))
		exit(-1);
	while (i < size)
	{
		if (!(map->edge_table[i] = (int *)malloc(sizeof(int) * size)))
			exit(-1);
		i++;
	}
    i = -1;
	while (++i < map->q_rooms)
	{
		j = -1;
		while (++j < map->q_rooms)
			map->edge_table[i][j] = map->et_wc[i][j];
	}
    j = -1;
	while (++j < size)
		map->edge_table[i][j] = 0;
}

int     ft_not_more_than_one_link(t_map *map, int i)
{
    int j;
    int counter;

    j = -1;
    counter = 0;
    while (++j < map->q_rooms)
    {
        if (map->edge_table[i][j] == 1)
            counter++;
    }
    return (counter);
}

void    ft_in_out_rooms(t_map *map)
{
    int i;
    int j;
    int out_room;

    i = -1;
    j = -1;
    out_room = map->real_rooms;
    ft_printf(" out_room = %d\n",  out_room);
    while (map->expand_et[++i] != -1)
    {

    }
}

void    ft_fucking_doubleroom(t_map *map, int links)
{
    ft_create_linkstable_of_size(map, links);
    ft_printf("links = %d\n", links);
    map->real_rooms = map->q_rooms;
    map->q_rooms = links;
    ft_printf("map->expand_et[0] = %d\n", map->expand_et[0]);
    ft_printf("map->expand_et[1] = %d\n", map->expand_et[1]);
    ft_printf("map->expand_et[2] = %d\n", map->expand_et[2]);
    ft_printlinkstable(map);
    ft_in_out_rooms(map);
}

void    ft_test(t_map *map)
{
    int counter;
    int i;
    int j;

    counter = 0;
    i = -1;
    j = map->ls_counter - 1;
    ft_create_expand_et(map);
    while(j > 1)
    {
        if ((counter = ft_not_more_than_one_link(map, map->bfs_str[j - 1])) != 1)
            map->expand_et[++i] = map->bfs_str[j - 1];
        j--;
        counter = 0;
    }
    if (i > -1)
        ft_fucking_doubleroom(map, map->q_rooms + i + 1);
}