/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:15:58 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/03 22:49:24 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	fill_in_path(t_path *ans, int i, int *mod, int ariw)
{
	int j;

	j = 0;
	if (*mod != 0)
	{
		ans[i].a_h = ariw + 1 - ans[i].size; // -2?
		(*mod)--;
	}
	else
		ans[i].a_h = ariw - ans[i].size;
	if (!(ans[i].p = (int *)malloc(sizeof(int) * ans[i].size)))
		exit(-1);
	while (j < ans[i].size)
		ans[i].p[j++] = 0;
	ans[i].p[0] = ans[i].a_h;
}

void		ft_preparations_for_print(t_path *ans, int cgp, int ants)
{
	int i;
	int ariw; // all_rooms_in_ways
	int mod; // остаток от деления

	i = -1;
	ariw = 0;
	(void)ants;
	while(++i < cgp)
		ariw += ans[i].size;
	mod = (ariw + ants) % cgp;
	ariw = (ariw + ants) / cgp;
	i = -1;
	while(++i < cgp)
		fill_in_path(ans, i, &mod, ariw);
}


void	ft_one_path_print(t_path *ans, t_map *map, int i, int nant)
{
	int j;

	j = ans[i].size - 2;
	if (ans[i].p[j + 1] != ans[i].a_h)
	{
		while (j >= 0)
		{
			if (j == ans[i].size - 2 && ans[i].p[j] != 0 && j != 0)
			{
				ft_printf("L%d-%s ", ans[i].p[j], map->str[ans[i].bfs[j + 1]]);
				ans[i].p[j] = 0;
				ans[i].p[j + 1]++;
			}
			else if (j == ans[i].size - 2 && j == 0 && ans[i].p[j] != 0)
			{
				ft_printf("L%d-%s ", nant, map->str[ans[i].bfs[j + 1]]);
				ans[i].p[0]--;
				ans[i].p[j + 1]++;
			}
			else if (j != 0 && ans[i].p[j + 1] == 0 && ans[i].p[j] != 0)
			{
				ft_printf("L%d-%s ", ans[i].p[j], map->str[ans[i].bfs[j + 1]]);
				ans[i].p[j + 1] = ans[i].p[j];
				ans[i].p[j] = 0;
			}
			else if (j == 0 && ans[i].p[j + 1] == 0 && ans[i].p[j] != 0)
			{
				ft_printf("L%d-%s ", nant, map->str[ans[i].bfs[j + 1]]);
				ans[i].p[j + 1] = nant;
				ans[i].p[j]--;
				//ft_printf("\n ans[i].p[j] = %d 111ans[%d].p[0] = %d, nant = %d\n", ans[i].p[j],  i, ans[i].p[0], nant);
				//ft_printf("\n ans[%d].p[0] = %d\n", i, ans[i].p[0]);
			}
			j--;
		}
	}
	if (ans[i].p[ans[i].size - 1] == ans[i].a_h)
	{
		//ft_printf("\nHello %d\n", i);
		map->e++;
		ft_intstrdel(&ans[i].p);
		return ;
	}

}

void write_size(t_path *ans, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("size %d = %d\n", i, ans[i].size);
		i++;
	}
}

void        ft_print_result(t_path *ans, t_map *map, int cgp, int ants)
{
	int i;
	int nant;

	nant = 0;
	map->e = 0;
	//write_size(ans, cgp);
    ft_preparations_for_print(ans, cgp, ants);
	while (1)
	{
		i = -1;
		while (++i < cgp)
		{
			if (ans[i].p != NULL)
			{
				if (ans[i].p[0] != 0)
					nant++;
				ft_one_path_print(ans, map, i, nant);
			}
		}
		if (map->e == cgp)
			return ;
		ft_printf("\n");
	}
}
