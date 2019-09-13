/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findonemoreway.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:32:26 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/13 14:36:57 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void    ft_cut_badlinks(t_map *map)
{
    t_goodway *new;
    int i;
    int j;
    int flag;

    i = -1;
    j = -1;
    flag = 0;
    new = (t_goodway *)map->goodways->content;
    while (++i < new->length - 1)
    {
        j = -1;
        while(++j < map->ls_counter - 1)
        {
            // ft_printf("new->bfs_str[%d] = %d\n", j, new->bfs_str[j]);
            // ft_printf("new->bfs_str[%d] = %d\n", j + 1, new->bfs_str[j + 1]);
            if ((map->bfs_str[j] == new->bfs_str[i] && map->bfs_str[j + 1] == new->bfs_str[i + 1])
                || (map->bfs_str[j + 1] == new->bfs_str[i] && map->bfs_str[j] == new->bfs_str[i + 1]))
            {
                ft_printf("Bad connections, bitches! Don't worry! We cut it!\n");
                ft_printf("map->bfs_str[%d] = %d\n", j, map->bfs_str[j]);
                ft_printf("map->bfs_str[%d] = %d\n", j + 1, map->bfs_str[j + 1]);
                map->edge_table[map->bfs_str[j]][map->bfs_str[j + 1]] = 0;
                map->edge_table[map->bfs_str[j + 1]][map->bfs_str[j]] = 0;
                flag = -1;
            }
        }
    }
    if (flag == 0)
    {
        i = 0;
        j = 0;
        while (++i < new->length - 2)
        {
            j = 0;
            while(++j < map->ls_counter - 2)
            {
                // ft_printf("new->bfs_str[%d] = %d\n", j, new->bfs_str[j]);
                // ft_printf("new->bfs_str[%d] = %d\n", j + 1, new->bfs_str[j + 1]);
                if (new->bfs_str[i] == map->bfs_str[j])
                {
                    ft_printf("Bad connections, bitches! Don't worry! We cut it!\n");
                    ft_printf("map->bfs_str[%d] = %d\n", j, map->bfs_str[j]);
                    map->edge_table[map->bfs_str[j]][map->bfs_str[j + 1]] = 0;
                    map->edge_table[map->bfs_str[j + 1]][map->bfs_str[j]] = 0;
                    flag++;
                }
            }
        }
        ft_printf("I realy don't know what to do we have the same %d non-links rooms!\n", flag);
    }
    if (flag == -1)
        ft_printf("That's cool man!\n"); // не круто// если у нас есть и общие линки и просто вершины,
        // а не только линки
}