/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_memory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:39:39 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/11 15:38:40 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_create_str_ways(t_map *map)
{
	int i;

	i = 0;
	if (!(map->ways = (int **)malloc(sizeof(int *) * map->q_rooms)))
		exit(-1);
}

static void ft_cwc_sup1(t_map *map, int *j, int *z)
{
    while (map->temp_line[*j] != -1 && map->bfs != 1)
	    {
		    map->ways[map->ls_counter][*z] = map->temp_line[*j];
		    if (map->ways[map->ls_counter][*z] == 1)
		    {
			    ft_intstrdel(&(map->ways[map->ls_counter]));
			    if (!(map->ways[map->ls_counter] = (int *)malloc(sizeof(int) * 2)))
				    exit(-1);
			    map->ways[map->ls_counter][0] = 1;
			    printf("BSF has done, for %d steps\n", map->ls_counter + 1);
			    map->bfs = 1;
		    }
		    (*z)++;
		    (*j)++;
	    }
	*j = 0;
	map->ways[map->ls_counter][*z] = -1;
	while (map->temp_line[*j] != -1 && *j < map->q_rooms)
		map->temp_line[(*j)++] = -1;
	map->ls_counter++;
}

void        ft_create_way_line(t_map *map, int quantity)
{
	int j;
	int z;

	j = 0;
	z = 0;
	if (map->ls_counter == 0)
	{
		if (!(map->ways[map->ls_counter] = (int *)malloc(sizeof(int) * (2))))
			exit(-1);
		map->ways[map->ls_counter][0] = 0;
		map->ways[map->ls_counter][1] = -1;
		map->ls_counter++;
		j = 0;
	}
	if (!(map->ways[map->ls_counter] = (int *)malloc(sizeof(int) * (quantity + 1))))
		exit(-1);
     ft_cwc_sup1(map, &j, &z);
}

void			ft_create_temp_line(t_map *map)
{
	int i;

	i = -1;
	if (!(map->temp_line = (int *)malloc(sizeof(int) * map->q_rooms)))
	 		exit(-1);
	while (++i < map->q_rooms)
		map->temp_line[i] = -1;
	map->temp_line[0] = 0;
}

void			ft_str_of_names(t_map *map)
{
	t_list	*temp;
	t_room	*curr_room;
	int		i;

	i = map->q_rooms - 1;
	if (!(map->str = (char**)malloc(sizeof(char*) * (map->q_rooms + 1))))
		exit(-1);
    map->str[map->q_rooms] = NULL;
	temp = map->rooms;
	while (map->rooms != NULL)
	{
		curr_room = (t_room *)map->rooms->content;
		map->str[i] = ft_strdup(curr_room->name);
		map->rooms = map->rooms->next;
		i--;
	}
	map->rooms = temp;
	temp = NULL;
}