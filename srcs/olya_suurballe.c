#include "lemin.h"

void init_split(t_farm *orgn, t_farm *new)
{
	int     i;
	t_room  *room;

	if (!(new->arr = malloc(sizeof(t_room*) * orgn->cnt * 2)))
		exit(-1);
	new->cnt = orgn->cnt;
	i = 0;
	while (i < orgn->cnt * 2)
	{
		if (!(new->arr[i] = ft_memalloc(sizeof(t_room))))
			exit(-1);
		room = new->arr[i];
		if (!(room->link = malloc(sizeof(int) * orgn->cnt)))
			exit(-1);
		room->pos = i;
		if (i < orgn->cnt)
			ft_memcpy(room->link, orgn->arr[i]->link, orgn->cnt * 4);
		else
			room->link[0] = -1; //or fill all -1?
		i++;
	}
	//olya_write_dfarm(new);
}

void	ft_dup_clear_farm(t_farm *pfarm, t_farm *orgn)
{
	int i;
	t_room *room;

	if (!(pfarm->arr = malloc(sizeof(t_room*) * orgn->cnt)))
		exit(-1);
	pfarm->cnt = orgn->cnt;
	i = 0;
	while (i < orgn->cnt)
	{
		if (!(pfarm->arr[i] = malloc(sizeof(t_room))))
			exit(-1);
		room = pfarm->arr[i];
		room->pos = i;
		room->paint_mark = -1;
		if (!(room->link = malloc(sizeof(int) * orgn->cnt)))
			exit(-1);
		room->link[0] = -1;
		i++;
	}
}

void ft_fill_path(t_path *path, int *bfs, int size)
{
	int i;

	path->size = size;
	i = 0;
	while (i < path->size)
	{
		path->bfs[i] = bfs[i];
		i++;
	}
}

void	ft_clean_links(t_farm *farm)
{
	int i;
	t_room *room;

	i = 0;
	while (i < farm->cnt)
	{
		room = farm->arr[i];
		//room->paint_mark = -1;
		room->link[0] = -1;
		i++;
	}
}

void search_new_path(t_path *good, int k, t_farm *split)
{
	int i;

	i = 0;
	while (i < k)
	{
		split_rev(&good[i], split);
		i++;
	}
}

void dup_link(int *dest_link, int *src_link)
{
	int i;

	i = 0;
	while (src_link[i] != -1)
	{
		dest_link[i] = src_link[i];
		i++;
	}
	dest_link[i] = src_link[i];
}

void back_to_origin(t_farm *farm, t_farm *orgn)
{
	int i;

	i = 0;
	while (i < orgn->cnt * 2)
	{
		if (i < orgn->cnt)
			dup_link(farm->arr[i]->link, orgn->arr[i]->link);
		else
			farm->arr[i]->link[0] = -1;		
		i++;
	}
}


t_path *ft_suurballe(t_farm *orgn, t_farm *split, t_farm *pfarm)
{
	t_path  *good;
	int     max_p;
	int     i;
	t_path  path;

	//good = NULL;
	max_p = split->mpw;
	if (!(good = ft_memalloc(sizeof(t_path) * max_p)))
		exit (-1);
	ft_fill_path(&path, split->bfs,  split->lwl);
	//olya_write_farm(orgn);
	i = 0;
	good[0] = path;
	//olya_write_dfarm(split);
	//olya_write_path(path);
	add_path(good, pfarm , i);
	olya_write_good(good, 1);
	while (++i < max_p)
	{
		search_new_path(good, i, split);
		//olya_write_dfarm(split);
		ft_bfs(split->arr, split->cnt, split);
		if (split->bfs_flag == 0)
			break ;
		ft_fill_path(&path, split->bfs,  split->lwl);
		good[i] = path;
		ft_printf("\n");
		olya_write_path(path);
		ft_printf("\n");
		add_path(good, pfarm, i);
		olya_write_good(good, i + 1);
		back_to_origin(split, orgn);
	}
	printf("max_p = %d", max_p);
	return (good);
}