/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:06:44 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/26 14:37:42 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		ft_bfs_finder_sup1(t_farm *farm, int *i, int *flag)
{
	*flag = 0;
	*i = farm->levels_of_ways_line;
	farm->bfs[0] = 0;
	farm->bfs[*i - 1] = 1;
	farm->bfs[*i] = -1;
}

static void		ft_bfs_finder_sup2(int *j, int *flag)
{
	*j = -1;
	*flag = 0;
}

static void		ft_bfs_finder_sup3(t_farm *farm, int *i, int *j, int *flag)
{
	farm->bfs[*i - 1] = farm->array_room[farm->ways_line[*i - 1][*j]]->pos;
	farm->ways_line[*i - 1][0] =
		farm->array_room[farm->ways_line[*i - 1][*j]]->pos;
	*flag = 1;
}

static void		ft_bfs_finder(t_farm *farm)
{
	int i;
	int j;
	int z;
	int flag;

	ft_bfs_finder_sup1(farm, &i, &flag);
	while (--i > 0)
	{
		ft_bfs_finder_sup2(&j, &flag);
		while (farm->ways_line[i - 1][++j] != -1)
		{
			z = -1;
			while (farm->array_room[farm->ways_line[i - 1][j]]->link[++z] != -1)
			{
				if (farm->ways_line[i][0] == farm->array_room[farm->ways_line[i - 1][j]]->link[z])
				{
					ft_bfs_finder_sup3(farm, &i, &j, &flag);
					break ;
				}
			}
			if (flag == 1)
				break ;	
		}
	}
}

static void		ft_check_and_right_to_wl(t_farm *farm, int number, int pos)
{
	int j;
	int z;
	int flag;

	j = -1;
	while (farm->array_room[number]->link[++j] != -1)
	{
		z = -1;
		flag = 0;
		while (farm->line[++z] != -1)
		{
			if (farm->array_room[number]->link[j] == farm->line[z])
			{
				flag = 1;
				break ;
			}
		}
		if (flag == 0)
		{
			farm->line[z] = farm->array_room[number]->link[j];
			farm->line[z + 1] = -1;
			farm->ways_line[pos][++farm->p] = farm->array_room[number]->link[j];
			farm->ways_line[pos][farm->p + 1] = -1;
			if (farm->ways_line[pos][farm->p] == 1)
			{
				farm->ways_line[pos][0] = 1;
				farm->ways_line[pos][1] = -1;
				farm->bfs_flag = 1;
				return ;
			}
		}
	}
}

void			ft_bfs(t_room **ar_r, int q_rooms, t_farm *farm)
{
	int i;
	int j;
	int z;

	i = 1;
	ft_fiil_in_ways_lines(farm);
	ft_fiil_in_line(farm);
	if (farm->bfs_flag == 1)
		return ;
	while (++i < q_rooms)
	{
		j = -1;
		farm->p = -1;
		while (farm->ways_line[i - 1][++j] != -1)
		{
			z = -1;
			while (ar_r[farm->ways_line[i - 1][j]]->link[++z] != -1)
			{
				ft_check_and_right_to_wl(farm, farm->ways_line[i - 1][j], i);
				if (farm->bfs_flag == 1)
				{
					farm->levels_of_ways_line = i + 1;
					ft_print_BFS_potensial(farm);
					ft_bfs_finder(farm);
					return ;
				}
			}
		}
		farm->mpw = (farm->p < farm->mpw) ? farm->p + 1 : farm->mpw;
	}
}

void	ft_solution(t_map *map, t_farm *farm)
{
	ft_str_of_names(map);
	ft_create_ways_lines(farm); // helper of BFS
	ft_create_line(farm);
	farm->count_room = map->q_rooms;
	ft_bfs(farm->array_room, farm->count_room, farm);
	ft_print_BFS(farm);
	if (farm->bfs_flag == 0)
		ft_cant_find_way_error();
	else if (farm->mpw == 1 || map->ants == 1)
		ft_print_way1(map, farm);
}
