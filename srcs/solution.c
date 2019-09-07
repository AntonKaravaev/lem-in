/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:06:44 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/07 20:29:32 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_easy_bfs(t_map *map)
{
	int str[map->q_rooms];
	int i;

	i = 0;
	while (i < map->q_rooms)
		str[i++] = -1;

}

void	ft_potentsial(t_map *map)
{
	int i;
	int start;
	int end;

	i = 1;
	start = 0;
	end = 0;
	while (i < map->q_rooms)
	{
		if (map->edge_table[0][i] == 1)
			start++;
		i++;
	}
	i = 0;
	while (i < map->q_rooms)
	{
		if (map->edge_table[1][i] == 1)
			end++;
		i++;
		if (i == 1)
			i++;
	}
	ft_printf("start = %d\n", start);
	ft_printf("end = %d\n", end);
	if ((start == 1 && end > 0) || (end == 1 && start > 0))
	{
		ft_printf("Not more than one way, only one way\n");
		ft_easy_bfs(map);
	}
	else
	{
		i = (start <= end) ? start : end;
		ft_printf("we have potentionaly %d ways\n", i);
	}

}

void	ft_let_ants_move(t_map *map)
{
	int finish;

	finish = 0;
	while (finish != map->ants)
	{
		finish++;
		ft_printf("L%s-%s\n", map->str[0], map->str[1]);
	}
}

void	ft_str_of_names(t_map *map)
{
	t_list	*temp;
	t_room	*curr_room;
	int		i;

	i = map->q_rooms - 1;
	if (!(map->str = (char**)malloc(sizeof(char*) * map->q_rooms)))
		exit (-1);
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

void	ft_solution(t_map *map)
{
	ft_str_of_names(map); // Создание двумерного массива имен(чтобы было легко к ним обратиться)
	if (map->edge_table[0][1] == 1)
	{
		ft_printf("Way has been finded (from start to end)\n");
		ft_let_ants_move(map);
	}
	else
	{
		ft_potentsial(map);
	}
}
