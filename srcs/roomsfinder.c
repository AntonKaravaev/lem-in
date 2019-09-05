/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roomsfinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:46:02 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/05 21:50:00 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_new_roominitial(t_map *map)
{
	t_room *new;

	new = NULL;
	if (!(new = (t_room *)malloc(sizeof(t_room))))
		exit (-1);
	new->name = NULL;
	new->x = 0;
	new->y = 0;
	new->pos = 0;
	new->name = ft_strdup(map->str[0]);
	new->x = ft_atoi(map->str[1]);
	new->y = ft_atoi(map->str[2]);
	new->pos = ++map->q_rooms - 1;
	map->new_room = new;
	new = NULL;
	ft_str2del(&map->str);
}

t_list		*ft_elem_of_rooms(t_map *map)
{
	t_list *new;

	new = NULL;
	if (!(new = (t_list *)malloc(sizeof(t_list))))
		exit (-1);
	new->content = (void *)map->new_room;
	new->content_size = (size_t)(sizeof(map->new_room));
	new->next = NULL;
	map->new_room = NULL;
	return (new);
}

void		ft_check_rooms(t_map *map)
{
	t_list	*temp;
	t_room	*last_room;
	t_room	*curr_room;

	temp = NULL;
	last_room = NULL;
	curr_room = NULL;
	temp = map->rooms;
	map->rooms = map->rooms->next;
	last_room = (t_room *)temp->content;
	ft_printf("last_room->name = %s\n", last_room->name);
	ft_printf("last_room->x = %d\n", last_room->x);
	ft_printf("last_room->y = %d\n", last_room->y);
	ft_printf("!last_room->pos = %d\n", last_room->pos);
	while (map->rooms != NULL)
	{
		curr_room = (t_room *)map->rooms->content;
		ft_printf("curr_room->name = %s\n", curr_room->name);
		ft_printf("curr_room->x = %d\n", curr_room->x);
		ft_printf("curr_room->y = %d\n", curr_room->y);
		ft_printf("!curr_room->pos = %d\n", curr_room->pos);
		if ((ft_strequ(last_room->name, curr_room->name) == 1)
			|| (last_room->x == curr_room->x && last_room->y == curr_room->y))
		{
			ft_putstr_fd("Error(Names or coors of rooms)\n", 2);
			exit(-1);
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

void		ft_find_start_room(char **line, t_map *map)
{
	t_list *temp;

	temp = NULL;
	map->str = ft_strsplit(*line, ' ');
	if (!map->str[0] || !map->str[1] || !map->str[2] || map->str[3] != NULL
		|| map->str[0][0] == 'L' || (ft_strchr(&(*map->str[0]), 45) != NULL))
		ft_lem_error("Error(start room) = \0", line);
	ft_atoicoor(&(*map->str[1]));
	ft_atoicoor(&(*map->str[2]));
	ft_new_roominitial(map);
	temp = ft_elem_of_rooms(map);
	ft_lstadd(&map->rooms, temp);
}

void		ft_find_curr_room(char **line, t_map *map)
{
	if (map->ef == 0)
		map->ef = 1;
	map->str = ft_strsplit(*line, ' ');
	if (!map->str[0] || !map->str[1] || !map->str[2] || map->str[3] != NULL
		|| map->str[0][0] == 'L' || (ft_strchr(&(*map->str[0]), 45) != NULL))
		ft_lem_error("Error(curr room) = \0", line);
	ft_atoicoor(&(*map->str[1]));
	ft_atoicoor(&(*map->str[2]));
	ft_new_roominitial(map);
	ft_lstadd(&map->rooms, ft_elem_of_rooms(map));
	ft_check_rooms(map);
}
