/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 13:53:48 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/05 23:01:16 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	ft_dellist(t_list *list)
{
	t_room	*temp;
	t_list	*next;

	while(list != NULL)
	{
		temp = (t_room	*)(list->content);
		ft_strdel(&(temp->name));
		ft_intstrdel(&(temp->link));
		next = list->next;
		free(list);
		list = next;
	}
	temp = NULL;
}

static void	ft_free_whats_needs(t_map *map, t_farm *farm)
{
	int i;
	t_room *room;

	ft_str2del(&map->str);
	ft_dellist(map->rooms);
	i = 0;
	while (i < farm->cnt)
	{
		room = farm->arr[i];
		free(room->name);
		free(room->link);
		free(room);
		i++;
	}
	free(farm->arr);
}

int			main(int argc, char *argv[])
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
	ft_free_whats_needs(&map, &farm);
	return (0);
}
