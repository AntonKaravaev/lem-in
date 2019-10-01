/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:06:44 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/26 23:56:10 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		ft_bfs_finder_sup1(t_farm *farm, int *i, int *flag)
{
	*flag = 0;
	*i = farm->lwl;
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
	farm->bfs[*i - 1] = farm->arr[farm->wl[*i - 1][*j]]->pos;
	farm->wl[*i - 1][0] =
		farm->arr[farm->wl[*i - 1][*j]]->pos;
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
		while (farm->wl[i - 1][++j] != -1)
		{
			z = -1;
			while (farm->arr[farm->wl[i - 1][j]]->link[++z] != -1)
			{
				if (farm->wl[i][0] == farm->arr[farm->wl[i - 1][j]]->link[z])
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

// static void		ft_crwl_sup1(t_farm *farm, int pos)
// {

// }

static void		ft_crwl_sup2(t_farm *farm, int pos)
{
	farm->wl[pos][0] = 1;
	farm->wl[pos][1] = -1;
	farm->bfs_flag = 1;
}

static void		ft_check_and_right_to_wl(t_farm *farm, int number, int pos)
{
	int j;
	int z;
	int flag;

	j = -1;
	while (farm->arr[number]->link[++j] != -1)
	{
		z = -1;
		flag = 0;
		while (farm->line[++z] != -1)
		{
			if (farm->arr[number]->link[j] == farm->line[z])
			{
				flag = 1;
				break ;
			}
		}
		if (flag == 0)
		{
			farm->line[z] = farm->arr[number]->link[j];
			farm->line[z + 1] = -1;
			farm->wl[pos][++farm->p] = farm->arr[number]->link[j];
			farm->wl[pos][farm->p + 1] = -1;
			if (farm->wl[pos][farm->p] == 1)
			{
				ft_crwl_sup2(farm, pos);
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
	//olya_write_farm(pfarm);
	if (ft_fiil_in_ways_lines(farm) == 1)
		return ;
	ft_fiil_in_line(farm);

	if (farm->bfs_flag == 1)
		return ;
	while (++i < q_rooms)
	{
		j = -1;
		farm->p = -1;
		//ft_printf("!!!! %d\n", i);
   		while (farm->wl[i - 1][++j] != -1)
		{
			//ft_printf("->>>>>>>>>> %d\n", j);
			z = -1;
			while (ar_r[farm->wl[i - 1][j]]->link[++z] != -1)
			{
				if (j > farm->cnt)
					return ;
				ft_check_and_right_to_wl(farm, farm->wl[i - 1][j], i);
				//olya_write_farm(pfarm);
				if (farm->bfs_flag == 1)
				{
					farm->lwl = i + 1;
					//ft_print_BFS_potensial(farm);
					ft_bfs_finder(farm);
					return ;
				}
			}
		}
		farm->mpw = (farm->p < farm->mpw) ? farm->p + 1 : farm->mpw;
	}
	//olya_write_farm(pfarm);
}

void	ft_solution(t_map *map, t_farm *farm)
{
	t_path *answer;
	t_farm split;
	t_farm pfarm;

	ft_str_of_names(map);
	farm->cnt = map->q_rooms;
	ft_farm_initial(&split, map);
	
	init_split(farm, &split);//olya
	
	ft_create_ways_lines(&split); // helper of BFS
	ft_create_line(&split);

	//ft_memset(&pfarm, 0, sizeof(t_farm));
//	ft_farm_initial(&pfarm, map);
	ft_bfs(split.arr, split.cnt, &split);
	ft_dup_clear_farm(&pfarm, farm->cnt);//olya

	if (split.bfs_flag == 0)
		ft_cant_find_way_error();
	else if (split.mpw == 1 || map->ants == 1)
	{
		ft_print_way1(map, &split);
		return ; 
	}
	//write_room(pfarm.arr[0]);
	//olya_write_farm(&pfarm);
	answer = ft_suurballe(farm, &split, &pfarm, map->ants);
}
