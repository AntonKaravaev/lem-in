/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:13:51 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/17 06:57:07 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			ft_create_expand_et(t_map *map)
{
	int i;

	i = -1;
	if (!(map->expand_et = (int *)malloc(sizeof(int) * map->q_rooms)))
	 		exit(-1);
	while (++i < map->q_rooms)
		map->expand_et[i] = -1;
}

void	ft_create_linkstable_of_size(t_map *map, int size)
{
	int		i;
	int		j;

	i = 0;
    if (map->edge_table != NULL)
		ft_intstr2del(&map->edge_table, map->q_rooms);
	if (!(map->edge_table = (int **)malloc(sizeof(int *) * size)))
		exit(-1);
	while (i < size)
	{
		if (!(map->edge_table[i] = (int *)malloc(sizeof(int) * size)))
			exit(-1);
		i++;
	}
    i = -1;
	while (++i < map->q_rooms)
	{
		j = -1;
		while (++j < map->q_rooms)
        {
            map->edge_table[i][j] = map->et_wc[i][j];
            printf("%d ", map->edge_table[i][j]);
        }
        --j;
        while (++j < size)
        {
            map->edge_table[i][j] = 0;
            printf("%d ", map->edge_table[i][j]);
        }
         map->edge_table[i][j] = -1;
         printf("\n");
	}
    i = i - 1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
        {
            map->edge_table[i][j] = 0;
            printf("%d ", map->edge_table[i][j]);
        } 
         map->edge_table[i][j] = -1;
         printf("\n");
	}
}

int     ft_not_more_than_one_link(t_map *map, int i) // ищит только те комнаты, которые нужно раздвоить
{
    int j;
    int counter;

    j = -1;
    counter = 0;
    while (++j < map->q_rooms)
    {
        if (map->edge_table[i][j] == 1)
            counter++;
    }
    return (counter);
}

void    ft_if_only_someone_look_at_me_and_i_am_not(t_map *map, int i, int out_room)
{
    int j;

    j = -1;
    while (++j < map->real_rooms)
    {
        if (map->edge_table[j][i] == 1 && map->edge_table[i][j] == 0)
        {
            map->edge_table[j][i] = 0;
            map->edge_table[j][out_room] = 1;
        }
    }
}

void    ft_in_out_rooms(t_map *map)
{
    int i;
    int j;
    int out_room;

    i = -1;
    out_room = map->real_rooms;
    ft_printf(" out_room = %d\n",  out_room);
    while (map->expand_et[++i] != -1)
    {
        ft_if_only_someone_look_at_me_and_i_am_not(map, map->expand_et[i], out_room);
        j = -1;
        while(++j < map->real_rooms)
        {
            if (map->edge_table[map->expand_et[i]][j] == 1 && map->edge_table[j][map->expand_et[i]] == 1)
            {
                map->edge_table[map->expand_et[i]][j] = 0;
                map->edge_table[out_room][j] = 1;
            }
        }
        map->edge_table[out_room][map->expand_et[i]] = 1;
        out_room++;
    }
}

void    ft_et_wc_sup(t_map *map)
{
    int i;
    int j;

    i = map->real_rooms;
    while (i < map->q_rooms)
    {
        j = -1;
        while (++j < map->q_rooms)
        {
            map->et_wc[i][j] = map->edge_table[i][j];
            map->et_wc[j][i] = map->edge_table[j][i];
        }  
        i++;
    }
}


void    ft_links_back_after_work(t_map *map)
{
    int i;

    i = -1;
    ft_printf("map->ways_to_go = %d\n", map->ways_to_go);
    ft_printf("map->bfs_str[%d] = %d\n", 0,  map->pl_dup[0]);
    //ft_printf("map->bfs_str[5] = %d\n", map->bfs_str[4]);
    while (++i < map->ways_to_go)
    {
        ft_printf("Hehehhe\n");
        map->edge_table[map->pl_dup[i]][map->pl_dup[--map->ways_to_go]] = 1;
    }
}

void    ft_fucking_doubleroom(t_map *map, int links)
{
ft_printf("\n\n");
ft_printlinkstable(map);
ft_printf("\n\n");

    ft_create_linkstable_of_size(map, links + 1);
    if (map->et_wc != NULL)
		ft_intstr2del(&map->et_wc, map->q_rooms);
    map->real_rooms = map->q_rooms;
    map->q_rooms = links;
    //ft_relinks_of_bfs_way(map);
    // ft_re_edge_table(map);
    ft_printf("links = %d\n", links);
    
    // ft_printf("map->expand_et[0] = %d\n", map->expand_et[0]);
    // ft_printf("map->expand_et[1] = %d\n", map->expand_et[1]);
    // ft_printf("map->expand_et[2] = %d\n", map->expand_et[2]);
    // ft_printlinkstable(map);
    ft_in_out_rooms(map);
    ft_et_wc(map);
    ft_printlinkstable(map);
    ft_et_wc_sup(map);
    // ft_et_wc(map);
    
    ft_re_initial_some_inf_in_map(map);
    // ft_re_edge_table(map);
    // ft_printlinkstable(map);
    ft_easy_bfs(map);
	ft_print_BFS(map);
    //ft_et_wc(map);
    ft_re_edge_table(map);
    ft_printlinkstable(map);
    // ft_printlinkstable(map);
    ft_links_back_after_work(map);
    // map->edge_table[8][1] = 1;
    // map->edge_table[5][8] = 1;
    // map->edge_table[9][5] = 1;
    // map->edge_table[2][9] = 1;
    // map->edge_table[0][2] = 1;
    //map->edge_table[5][4] = 1;
    // ft_printf("map->ls_counter = %d\n", map->ls_counter);
    ft_printlinkstable(map);
    ft_find_bfs(map);

}

void    ft_reverse_int_mas(t_map *map)
{
    ft_printf("%d\n", map->ways_to_go);
    int i;
    int j;
    int temp;

    i = 0;
    j = map->ways_to_go - 1;
    while (i < j)
    {
        temp =  map->pl_dup[i];
        map->pl_dup[i] = map->pl_dup[j];
        map->pl_dup[j] = temp;
        i++;
        j--;
    }
    i = 0;
    while (i < map->ways_to_go)
    {
        ft_printf("map->bfs_str[%d] = %d\n", i ,map->pl_dup[i]);
        i++;
    }
}

int     ft_double_room(t_map *map, int room_curr, int morerooms)
{
    int j;

    j = -1;
    while (++j < morerooms)
    {
        if (room_curr == map->expand_et[j])
            return 1;
    }
    return (0);
}

void   ft_for_change_links_back(t_map *map)
{
    int morerooms;
    int i;
    int j;
    int temp[map->ls_counter];

    i = map->ls_counter;
    j = -1;
    while (++j < map->ls_counter)
    {
        temp[j] = map->bfs_str[--i];
        ft_printf("temp[%d] = %d\n", j, temp[j]);
    }
    i = -1;
	if (!(map->pl_dup = (int *)malloc(sizeof(int) * map->ways_to_go)))
	 		exit(-1);
	while (++i < map->ways_to_go)
		map->pl_dup[i] = -1;
    i = -1;
    j = 0;
    morerooms = map->q_rooms;
    while (++i < map->ways_to_go)
    {
        if (ft_double_room(map, temp[j], map->ways_to_go) == 1)
        {
            map->pl_dup[i++] = morerooms++;
            ft_printf("map->bfs_str[%d] = %d\n", i - 1, map->pl_dup[i - 1]);
            map->pl_dup[i] = temp[j];
             ft_printf("map->bfs_str[%d] = %d\n", i, map->pl_dup[i]);
        }
        else
        {
            map->pl_dup[i] = temp[j];
            ft_printf("map->bfs_str[%d] = %d\n", i, map->pl_dup[i]);
        }
        j++;
    }
    ft_reverse_int_mas(map);
}

void    ft_test(t_map *map)
{
    int counter;
    int i;
    int j;

    counter = 0;
    i = -1;
    j = map->ls_counter - 1;
    ft_create_expand_et(map);
    while(j > 1)
    {
        if ((counter = ft_not_more_than_one_link(map, map->bfs_str[j - 1])) != 1)
           map->expand_et[++i] = map->bfs_str[j - 1]; // Хранятся комнаты которые буду раздваивать
        j--;
        counter = 0;
    }
    if (i > -1)
    {
        map->ways_to_go = map->ls_counter + i + 1;
        ft_for_change_links_back(map);
        ft_fucking_doubleroom(map, map->q_rooms + i + 1);
    }
}