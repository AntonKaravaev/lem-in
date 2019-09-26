/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_memory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:39:39 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/26 23:47:14 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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

void	ft_create_ways_lines(t_farm *farm)
{
	int i;

	i = -1;
	if (!(farm->wl = (int **)malloc(sizeof(int *) * 1000)))
		exit (-1);
	while (++i < 1000)
	{
		if (!(farm->wl[i] = (int *)malloc(sizeof(int) * 1000)))
			exit (-1);
	}
}

void	ft_fiil_in_ways_lines(t_farm *farm)
{
	int i;

	farm->wl[0][0] = 0;
	farm->wl[0][1] = -1;
	farm->mpw = 0;
	i = -1;
	while (farm->arr[0]->link[++i] != -1)
	{
		farm->wl[1][i] = farm->arr[0]->link[i];
		farm->mpw++;
	}	
	farm->wl[1][i] = -1;
}

void	ft_create_line(t_farm *farm)
{
	if (!(farm->line = (int *)malloc(sizeof(int) * 1000)))
		exit (-1);
}

void	ft_fiil_in_line(t_farm *farm)
{
	int i;

	farm->bfs_flag = 0;
	farm->line[0] = 0;
	farm->line[1] = -1;
	if (farm->bfs == NULL)
	{
		if (!(farm->bfs = (int *)malloc(sizeof(int) * 1000)))
			exit (-1);
	}
	farm->bfs[0] = -1;
	i = -1;
	while (farm->arr[0]->link[++i] != -1)
		farm->line[i + 1] = farm->arr[0]->link[i];
	farm->line[i + 1] = -1;
}