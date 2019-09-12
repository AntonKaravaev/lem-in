/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:06:44 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/12 22:19:17 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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

int				ft_how_much_for_one_line(t_map *map, int i, int z)
{
	int j;

	j = -1;
	while (++j < map->q_rooms)
	{
		if (map->edge_table[i][j] == 1 && i == 0)
		{
			map->temp_line[z++] = j;
			map->edge_table[i][j] = 0;
			//map->edge_table[j][i] = 0;
		}
		else if (map->edge_table[i][j] == 1)
		{
			if (ft_check_renumber(map, z, j) == 1)
			{
				map->edge_table[i][j] = 0;
				//map->edge_table[j][i] = 0;
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
	//ft_print_BFS(map);
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

static void		ft_potensial_sup1(t_map *map, int *i, int *start, int *end)
{
	while (*i < map->q_rooms)
	{
		if (map->edge_table[0][*i] == 1)
			(*start)++;
		(*i)++;
	}
	*i = 0;
	while (*i < map->q_rooms)
	{
		if (map->edge_table[1][*i] == 1)
			(*end)++;
		(*i)++;
		if (*i == 1)
			(*i)++;
	}
}

void		ft_relinks_of_bfs_way(t_map *map)
{
	int i;
	int	j;

	i = 0;
	while (i < map->ls_counter - 1)
	{
		map->edge_table[map->bfs_str[i]][map->bfs_str[i + 1]] = 0;
		i++;
	}

	i = 0;
	ft_printf("    0 1 2 3 4 5 6 7 8\n");
	ft_printf("   __________________\n");
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
	ft_printf("   ------------------\n");
}


void			ft_et_wc(t_map *map)
{
	int	i;
	int j;

	i = 0;
	if (!(map->et_wc = (int **)malloc(sizeof(int *) * map->q_rooms)))
		exit(-1);
	while (i < map->q_rooms)
	{
		if (!(map->et_wc[i] =  (int *)malloc(sizeof(int) * map->q_rooms)))
			exit(-1);
		i++;
	}
	i = -1;
	while (++i < map->q_rooms)
	{
		j = -1;
		while (++j < map->q_rooms)
			map->et_wc[i][j] = map->edge_table[i][j];
	}
}

void	ft_re_edge_table(t_map *map)
{
	int	i;
	int j;

	i = 0;
	ft_intstr2del(&map->edge_table, map->q_rooms);
	if (!(map->edge_table = (int **)malloc(sizeof(int *) * map->q_rooms)))
		exit(-1);
	while (i < map->q_rooms)
	{
		if (!(map->edge_table[i] =  (int *)malloc(sizeof(int) * map->q_rooms)))
			exit(-1);
		i++;
	}
	i = -1;
	while (++i < map->q_rooms)
	{
		j = -1;
		while (++j < map->q_rooms)
			map->edge_table[i][j] = map->et_wc[i][j];
	}
}

void	ft_re_initial_some_inf_in_map(t_map *map)
{
	// int i;

	// i = 0;
	//while ()
	//ft_intstrdel(map->ways[i])
	// printf("map->ways[0][0] = %d\n", map->ways[0][0]);
	// printf("map->ways[0][1] = %d\n", map->ways[0][1]);
	// printf("map->ways[0][2] = %d\n", map->ways[0][2]);
	// printf("map->ways[0][3] = %d\n", map->ways[0][3]);
	ft_intstrdel(&map->bfs_str);

	ft_intstr2del(&map->ways, map->ls_counter);
	map->bfs = 0;
	map->ls_counter = 0;
}

void			ft_potentsial(t_map *map)
{
	int i;
	int start;
	int end;

	i = 1;
	start = 0;
	end = 0;
	ft_potensial_sup1(map, &i, &start, &end);
	//ft_printf("#start = %d\n", start);
	//ft_printf("#end = %d\n", end);
	ft_et_wc(map);
	ft_easy_bfs(map);
	if (map->bfs == 0)
		ft_cant_find_way_error();
	else if (start == 1 || end == 1 || map->ants == 1)
	{
		//ft_printf("#Not more than one way, only one way\n");
		ft_print_way1(map);
	}
	else
	{
		i = (start <= end) ? start : end;
		ft_printf("#We have potentionaly %d ways\n", i);
		ft_create_list_of_goodways(map);
		ft_re_edge_table(map);
		ft_relinks_of_bfs_way(map); // ставит линки в одну сторону чтобы найти в
		// будущем пересечения
		ft_re_initial_some_inf_in_map(map);
		ft_easy_bfs(map);
		ft_find_bfs(map);
		ft_printf("map->bfs_str[0] = %d\n", map->bfs_str[0]);
		ft_printf("map->bfs_str[1] = %d\n", map->bfs_str[1]);
		ft_printf("map->bfs_str[2] = %d\n", map->bfs_str[2]);
		ft_printf("map->bfs_str[3] = %d\n", map->bfs_str[3]);
		ft_printf("map->bfs_str[4] = %d\n", map->bfs_str[4]);
		ft_printf("map->bfs_str[5] = %d\n", map->bfs_str[5]);
		ft_printf("map->bfs_str[6] = %d\n", map->bfs_str[6]);
		ft_printf("map->bfs_str[7] = %d\n", map->bfs_str[7]);
		//ft_print_way1(map);

		//ft_save_goodway(map);
	}
}

void			ft_solution(t_map *map)
{
	ft_str_of_names(map);
	if (map->edge_table[0][1] == 1)
	{
		//ft_printf("#Way has been finded (from start to end)\n");
		ft_let_ants_move(map);
	}
	else
		ft_potentsial(map);
}
