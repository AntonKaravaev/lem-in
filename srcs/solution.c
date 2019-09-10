/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:06:44 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/10 21:50:02 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		ft_create_str_ways(t_map *map)
{
	int i;

	i = 0;
	if (!(map->ways = (int **)malloc(sizeof(int *) * map->q_rooms)))
		exit(-1);
}

static void		ft_create_way_line(t_map *map, int quantity)
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
	while (map->temp_line[j] != -1 && map->bfs != 1)
	{
		map->ways[map->ls_counter][z] = map->temp_line[j];
		if (map->ways[map->ls_counter][z] == 1)
		{
			ft_intstrdel(&(map->ways[map->ls_counter]));
			if (!(map->ways[map->ls_counter] = (int *)malloc(sizeof(int) * 2)))
				exit(-1);
			map->ways[map->ls_counter][0] = 1;
			printf("BSF has done, for %d steps\n", map->ls_counter + 1);
			map->bfs = 1;
		}
		z++;
		j++;
	}
	j = 0;
	map->ways[map->ls_counter][z] = -1;
	while (map->temp_line[j] != -1 && j < map->q_rooms)
		map->temp_line[j++] = -1;
	map->ls_counter++;
}

static int		ft_check_renumber(t_map *map, int i, int number)
{
	int j;
	int m;
	int z;

	j = 0;
	m = -1;
	while (++m < map->ls_counter)
	{
		z = -1;
		while (map->ways[m][++z] != -1)
		{
			if (map->ways[m][z] == number)
				return (0);
		}
	}
	while (j < map->q_rooms && map->temp_line[j] != -1 && j < i)
	{
		if (map->temp_line[j] == number)
			return (0);
		j++;
	}
	return (1);
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

int				ft_how_much_for_one_line(t_map *map, int i, int z)
{
	int j;

	j = -1;
	while (++j < map->q_rooms)
	{
		if (map->edge_table[i][j] == 1 && i == 0)
		{
			map->temp_line[z++] = j;
			//map->edge_table[i][j] = 0;
			map->edge_table[j][i] = 0;
		}
		else if (map->edge_table[i][j] == 1)
		{
			if (ft_check_renumber(map, z, j) == 1)
			{
				//map->edge_table[i][j] = 0;
				map->edge_table[j][i] = 0;
				map->temp_line[z] = j;
				// printf("map->temp_line[%d] = %d\n", z, map->temp_line[z]);
				z++;
			}
		}
	}
	return (z);
}

void			ft_easy_bfs(t_map *map)
{
	int i;
	int j;
	int z;

	ft_printlinkstable(map);
	ft_create_str_ways(map);
	ft_create_temp_line(map);
	ft_create_way_line(map, ft_how_much_for_one_line(map, 0, 0));
	ft_print_BFS(map);
	while (map->bfs != 1)
	{
		z = 0;
		i = 0;
		while (++i < map->ls_counter)
		{
			j = -1;
			while (map->ways[i][++j] != -1 && map->bfs != 1)
				z = ft_how_much_for_one_line(map, map->ways[i][j], z);
		}
		if (z == 0)
			break;
		ft_create_way_line(map, z);
	}
	ft_printlinkstable(map);
	ft_print_BFS(map);
	ft_find_bfs(map);
}

void			ft_potentsial(t_map *map)
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
		ft_easy_bfs(map);
	}

}

void			ft_let_ants_move(t_map *map)
{
	int finish;

	finish = 0;
	while (finish != map->ants)
	{
		finish++;
		ft_printf("L%s-%s\n", map->str[0], map->str[1]);
	}
}

void			ft_str_of_names(t_map *map)
{
	t_list	*temp;
	t_room	*curr_room;
	int		i;

	i = map->q_rooms - 1;
	if (!(map->str = (char**)malloc(sizeof(char*) * map->q_rooms)))
		exit(-1);
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

void			ft_solution(t_map *map)
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
