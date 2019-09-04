/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roomsfinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:46:02 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/04 19:48:33 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_find_start_room(char **line, t_map *map)
{
	t_room *start;
	t_room *tmp;

	map->str = ft_strsplit(*line, ' ');
	if (!map->str[0] || !map->str[1] || !map->str[2] || map->str[3] != NULL
		|| map->str[0][0] == 'L' || (ft_strchr(&(*map->str[0]), 45) != NULL))
	{
		ft_putstr_fd("Error( start room)\n", 2);
		exit(-1);
	}
	ft_atoicoor(&(*map->str[1]));
	ft_atoicoor(&(*map->str[2]));
	if (!(start = (t_room *)malloc(sizeof(t_room))))
		exit (-1);
	start->name = map->str[0];
	start->x = ft_atoi(map->str[1]);
	start->y = ft_atoi(map->str[2]);
	ft_strdel(map->str); // Оля объсняла как зафришить филлер
	if (!(map->rooms = (t_list *)malloc(sizeof(t_list))))
		exit (-1);
	map->rooms->content = (void *)start;
	map->rooms->content_size = sizeof(t_room);
	map->rooms->next = NULL;
	tmp = map->rooms->content;
	start = NULL;
	printf("x = %d\n", tmp->x);
	printf("y = %d\n", tmp->y);
}

// void		ft_find_room(char **line, t_map *map)
// {
// 	map->str = ft_strsplit(*line, " ")
// 	if (!map->str[0] || !map->str[1] || !map->str[2] || map->str[3] != NULL
// 		|| map->str[0][0] == 'L' )
// 	{
// 		ft_putstr_fd("Error(room)\n", 2);
// 		exit(-1);
// 	}
// 	ft_atoicoor(&(*map->str[1]));
// 	ft_atoicoor(&(*map->str[2]));
// 	str2 = map->str;
// 	ft_strdel(map->str);
// 	map->str = ft_strstrjoin()
// }
