/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savelinks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:21:17 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/08 14:09:59 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	ft_create_linkstable(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	if (!(map->edge_table = (int **)malloc(sizeof(int *) * map->q_rooms)))
		exit(-1);
	while (i < map->q_rooms)
	{
		if (!(map->edge_table[i] = (int *)malloc(sizeof(int) * map->q_rooms)))
			exit(-1);
		i++;
	}
	i = -1;
	while (++i < map->q_rooms)
	{
		j = -1;
		while (++j < map->q_rooms)
			map->edge_table[i][j] = 0;
	}
}

static int	ft_fiil_in_links_sup1(t_list **temp, t_map *map, t_room **curr_room,
	int *nameandlink)
{
	if (*nameandlink == 1)
	{
		map->temp_x = (*curr_room)->pos;
		map->rooms = map->rooms->next;
		*curr_room = NULL;
	}
	else if (*nameandlink == 2)
	{
		map->temp_y = (*curr_room)->pos;
		map->edge_table[map->temp_x][map->temp_y] = 1;
		map->edge_table[map->temp_y][map->temp_x] = 1;
		map->rooms = *temp;
		*temp = NULL;
		return (1);
	}
	return (0);
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
		if (ft_strequ(map->str[0], curr_room->name)
			|| ft_strequ(map->str[1], curr_room->name))
		{
			nameandlink++;
			if (ft_fiil_in_links_sup1(&temp, map, &curr_room,
				&nameandlink) == 1)
				return ;
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

static void	ft_savelinks_sup1(char **line, t_map *map)
{
	if (map->str[0] != NULL && map->str[1] != NULL && map->str[2] == NULL
		&& ft_strequ(map->str[0], map->str[1]) == 0)
	{
		ft_fiil_in_links(map);
		ft_str2del(&map->str);
		map->temp_x = 0;
		map->temp_y = 0;
	}
	else
		ft_lem_error("Error(links) = \0", line);
}

void		ft_savelinks(char **line, t_map *map)
{
	if (map->lf == 0)
	{
		map->lf++;
		ft_create_linkstable(map);
	}
	if (*line && *line[0] != '-' && ft_strchr(*line, 45) != NULL)
	{
		map->str = ft_strsplit(*line, ' ');
		if (map->str[0] != NULL && map->str[1] == NULL)
		{
			ft_str2del(&map->str);
			map->str = ft_strsplit(*line, '-');
			ft_savelinks_sup1(line, map);
		}
		else
			ft_lem_error("Error(links) = \0", line);
	}
	else
		ft_lem_error("Error(links) = \0", line);
}
