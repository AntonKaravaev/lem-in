/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:06:44 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/08 18:47:07 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void ft_create_str_ways(t_map *map)
{
	int i;
//	int j;

	i = 0;
	if (!(map->ways = (int **)malloc(sizeof(int *) * map->q_rooms)))
		exit(-1);
}

static void ft_create_way_line(t_map *map, int i, int quantity)
{
	int j;
	int z;

	j = 0;
	z = 0;
	if (!(map->ways[i] = (int *)malloc(sizeof(int) * (quantity + 1))))
		exit(-1);
	while (map->temp_line[j] != -1)
		map->ways[i][z++] = map->temp_line[j++];
	j = 0;
	map->ways[i][z] = -1;
	while (map->temp_line[j] != -1 && j < map->q_rooms)
		map->temp_line[j++] = -1;
}

static int		ft_check_renumber(t_map *map, int i, int number)
{
	int j;

	j = 0;
	while (j < map->q_rooms && map->temp_line[j] != -1 && j < i)
	{
		ft_printf("map->temp_line[%d] = %d, *number = %d\n", j, map->temp_line[j], number);
		if (map->temp_line[j] == number)
			return (0);
		j++;
	}
	return (1);
}

void		ft_create_temp_line(t_map *map)
{
	int i;

	i = -1;
	if (!(map->temp_line = (int *)malloc(sizeof(int) * map->q_rooms)))
	 		exit(-1);
	while (++i < map->q_rooms)
		map->temp_line[i] = -1;
}

int		ft_how_much_for_one_line(t_map *map, int i)
{
	int j;
	int z;

	j = -1;
	z = 0;
	while (++j < map->q_rooms)
	{
		if (map->edge_table[i][j] == 1 && i == 1)
		{
			map->temp_line[z] = j;
			z++;
		}
		else if (map->edge_table[i][j] == 1)
		{
			if (ft_check_renumber(map, z , j) == 1)
			{
				map->temp_line[z] = j;
				z++;
			}
		}
	}
	ft_printf("z = %d\n", z);
	return (z);
}

void	ft_easy_bfs(t_map *map)
{
	int i;
	int j;
	int z;

	i = 0;
	j = -1;
	z = -1;
	ft_create_str_ways(map);
	ft_create_temp_line(map);
	ft_create_way_line(map, 0, ft_how_much_for_one_line(map, 1));
	ft_create_way_line(map, 1, ft_how_much_for_one_line(map, map->ways[0][0]));
	//printf("map->ways[0][0] = %d\n", map->ways[0][0]);
	// while (++j < map->q_rooms)
	// {
	// 	if (map->edge_table[1][j] == 1)
	// 	{
	// 		z++;
	// 		if (ft_check_renumber(map, &i, &j) == 1)
	// 			map->ways[i][z] = j;
	// 	}
	// 	map->edge_table[j][1] = 0;
	// 	map->edge_table[1][j] = 0;
	// }
	i = 0;
	ft_printf("|0|  |1|  |2|  |3|  |4| |5|\n");
	while (map->ways[0][i] != -1)
	{
		ft_printf("|%d| ", map->ways[0][i]);
		i++;
	}
	ft_printf("\n");
	i = 0;
	ft_printf("|0|  |1|  |2|  |3|  |4| |5|\n");
	while (map->ways[1][i] != -1)
	{
		ft_printf("|%d| ", map->ways[1][i]);
		i++;
	}
	ft_printf("\n");
	ft_printlinkstable(map);
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
