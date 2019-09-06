/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savelinks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:21:17 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/06 17:37:19 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"


void		ft_create_linkstable(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	if (!(map->edge_table = (int **)malloc(sizeof(int *) * map->q_rooms)))
		exit (-1);
	while (i < map->q_rooms)
	{
		if (!(map->edge_table[i] = (int *)malloc(sizeof(int) * map->q_rooms)))
			exit (-1);
		i++;
	}
	i = 0;
	ft_printf("    0 1 2 3 4 5\n");
	ft_printf("   _____________\n");
	while (i < map->q_rooms)
	{
		j = 0;
		ft_printf("%d  |", i);
		while (j < map->q_rooms)
		{
			map->edge_table[i][j] = 0;
			ft_printf("%d|", map->edge_table[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("   -------------\n");
}

void		ft_printlinkstable(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	ft_printf("    0 1 2 3 4 5\n");
	ft_printf("   _____________\n");
	while (i < map->q_rooms)
	{
		j = 0;
		ft_printf("%d  |", i);
		while (j < map->q_rooms)
		{
			ft_printf("%d|", map->edge_table[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("   -------------\n");
}

void		ft_fiil_in_links(t_map *map)
{
	t_list	*temp;
	t_room	*curr_room;
	int		nameandlink;

	nameandlink = 0;
	temp = map->rooms;
	while (map->rooms != NULL)
	{
		curr_room = (t_room *)map->rooms->content;
		if (ft_strequ(map->str[0], curr_room->name) || ft_strequ(map->str[1], curr_room->name))
		{
			nameandlink++;
			if (nameandlink == 1)
			{
				map->temp_x = curr_room->pos;
				map->rooms = map->rooms->next;
				curr_room = NULL;
			}
			else if (nameandlink == 2)
			{
				map->temp_y = curr_room->pos;
				nameandlink++;
				ft_printf("map->temp_x = %d map->temp_y =%d\n", map->temp_x, map->temp_y);
				map->edge_table[map->temp_x][map->temp_y] = 1;
				map->edge_table[map->temp_y][map->temp_x] = 1;
				map->rooms = temp;
				temp = NULL;
				return ;
			}
		}
		else
		{
			map->rooms = map->rooms->next;
			curr_room = NULL;
		}
	}
	map->rooms = temp;
	temp = NULL;
}

void		ft_savelinks(char **line, t_map *map)
{
	if (map->lf == 0)
	{
		map->lf++;
		ft_printf("map->q_rooms = %d\n", map->q_rooms);
		ft_create_linkstable(map);
	}
	if (*line && *line[0] != '-' && ft_strchr(*line, 45) != NULL)
	{
		map->str = ft_strsplit(*line, ' ');
		if (map->str[0] != NULL && map->str[1] == NULL)
		{
			ft_str2del(&map->str);
			map->str = ft_strsplit(*line, '-');
			ft_printf("map->str[0] = %s\n", map->str[0]);
			ft_printf("map->str[1] %s\n", map->str[1]);
			if (map->str[0] != NULL && map->str[1] != NULL && map->str[2] == NULL && ft_strequ(map->str[0], map->str[1]) == 0)
			{
				ft_fiil_in_links(map);
				ft_str2del(&map->str);
				map->temp_x = 0;
				map->temp_y = 0;
				ft_printf("WORK! \n");
			}
			else
				ft_lem_error("Error(links) = \0", line);
		}
		else
			ft_lem_error("Error(links) = \0", line);
	}
	else
		ft_lem_error("Error(links) = \0", line);
	ft_printf("Final links_table\n");
	ft_printlinkstable(map);
}
