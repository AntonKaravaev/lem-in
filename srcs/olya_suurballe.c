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
	//olya_write_farm(new);
}

void ft_fill_path(t_path *path, int *bfs, int size)
{
	int i;

	(void)bfs;
	path->size = size;
	i = 0;
	while (i < path->size)
	{
		path->bfs[i] = bfs[i];
		i++;
	}
}

t_path *ft_suurballe(t_farm *orgn)
{
	t_farm  split;
	t_path  *good;
	int     max_p;
	//int     i;
	t_path  path;

	//good = NULL;
	init_split(orgn, &split);
	max_p = orgn->mpw;
	if (!(good = ft_memalloc(sizeof(t_path) * max_p)))
		exit (-1);
	ft_fill_path(&path, orgn->bfs,  orgn->lwl);
	
//	i = 0;
	split_rev(&path, &split);
	/*
	while (i < max_p)
	{
		
		i++;
	}
	*/
	return (good);
}