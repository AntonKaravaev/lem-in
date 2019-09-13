/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_goodways.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:49:57 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/13 16:16:08 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void     ft_save_goodway(t_map *map)
{ // записали данные в структура 1 хор.пути
// чтобы сохранить в список хороших путей
    int i;

    i = -1;
    if (!(map->n_g = (t_goodway *)malloc(sizeof(t_goodway))))
        exit (-1);
    map->n_g->length = map->ls_counter;
    if (!(map->n_g->bfs_str = (int *)malloc(sizeof(int) * map->ls_counter)))
         exit (-1);
    while (++i < map->ls_counter)
        map->n_g->bfs_str[i] = map->bfs_str[i];
    map->n_g->lines_of_steps = map->ls_counter - 1 + map->ants - 1;
}

t_list	*ft_elem_of_goodways(t_map *map)
{
	t_list *new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		exit(-1);
    ft_save_goodway(map);
	new->content = (void *)map->n_g;
	new->content_size = (size_t)(sizeof(map->n_g));
	new->next = NULL;
	map->n_g = NULL;
	return (new);
}

void            ft_create_list_of_goodways(t_map *map)
{
    map->goodways = ft_elem_of_goodways(map);
    map->ways_to_go = 1;
}

//     ft_lstadd(&map->goodways, temp);