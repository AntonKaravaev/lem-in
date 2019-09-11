/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:34:03 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/11 17:47:51 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void     ft_print_way1_sup(t_map *map, int *z, int *j, int *num_ant)
{
    *z = ++(*j);
    if (*z < map->ls_counter - 1)
        *num_ant = 1;
    else if (map->sf > 0)
    {
        *z = --(*j);
        *num_ant = ++map->ef + 1;
    }
    else
    {
        *z = --(*j);
        *num_ant = ++map->ef + 1;
    }
}

void            ft_print_way1(t_map *map)
{
    int i;
    int j;
    int z;
    int num_ant;

    i = map->ants + (map->ls_counter - 1) - 1;
    j = -1;
    z = 0;
    map->sf = map->ants;
    map->ef = 0;
    while (i-- > 0)
    {
        ft_print_way1_sup(map, &z, &j, &num_ant);
        while (z > 0 && num_ant < map->ants)
        {
            ft_printf("L%d-%s ", num_ant, map->str[map->bfs_str[z + 1]]);
            z--;
            num_ant++;
        }
            ft_printf("L%d-%s\n", num_ant, map->str[map->bfs_str[z + 1]]);
        map->sf--;
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