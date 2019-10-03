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
		{
			ft_memcpy(room->link, orgn->arr[i]->link, orgn->cnt * 4);
		//	printf("%p\n%p\n\n", room->link, orgn->arr[i]->link);
		}
		else
			room->link[0] = -1; //or fill all -1?
		i++;
	}
	//olya_write_dfarm(new);
}

void	ft_dup_clear_farm(t_farm *pfarm, int cnt)
{
	int i;
	t_room *room;

	if (!(pfarm->arr = malloc(sizeof(t_room*) * cnt)))
		exit(-1);
	pfarm->cnt = cnt;
	i = 0;
	while (i < cnt)
	{
		if (!(pfarm->arr[i] = malloc(sizeof(t_room))))
			exit(-1);
		room = pfarm->arr[i];
		room->pos = i;
		room->paint_mark = -1;
		if (!(room->link = malloc(sizeof(int) * cnt)))
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

void ft_pathcp(t_path *save, t_path *good, int k)
{
	int i;
	int j;

	i = 0;
	while (i < k + 1)
	{
		save[i].size = good[i].size;
		j = 0;
		while (j < save[i].size)
		{
			save[i].bfs[j] = good[i].bfs[j];
			j++;
		}	
		i++;
	}
}

int worse(t_path *old, t_path *new, int k, int aunts)
{
	int old_sum;
	int new_sum;
	int i;

	i = 0;
	old_sum = 0;
	new_sum = 0;
//	printf("\nCHEK %d in save\n", k);
	while (i < k)
	{
//		ft_printf("i = %d, old.size = %d, new.size = %d\n", i, old[i].size, new[i].size);
		old_sum += old[i].size;
		new_sum += new[i].size;
		i++;
	}
	new_sum += new[i].size;
//	ft_printf("i = %d, new.size = %d\n", i, new[i].size);
	old_sum += aunts;
	new_sum += aunts;
	old_sum = old_sum % k > 0 ? (old_sum / k + 1) : old_sum / k;
	k++;
	new_sum = new_sum % k > 0 ? (new_sum / k + 1) : new_sum / k;
	i = 0;
	while (i < k)
	{
		if (new_sum <= new[i].size)// <= ???
			return (1);
		i++;
	}
	//
//	ft_printf("in answer old = %d new = %d\n\n", old_sum, new_sum);
	return (old_sum < new_sum);
}


t_path *ft_suurballe(t_farm *orgn, t_farm *split, t_farm *pfarm, int aunts)
{
	t_path  *good;
	int     max_p;
	int     i;
	t_path  path;
	t_path	*save;

	max_p = split->mpw;
	if (!(good = ft_memalloc(sizeof(t_path) * max_p)))
		exit (-1);
	if (!(save = ft_memalloc(sizeof(t_path) * max_p)))
		exit (-1);
	ft_fill_path(&path, split->bfs,  split->lwl);
	i = 0;
	good[0] = path;
	add_path(good, pfarm , i);
	ft_pathcp(save, good, 0);
	i++;
	while (i < max_p && i < aunts)
	{
		search_new_path(good, i, split);//!	;
		ft_bfs(split->arr, split->cnt, split);//!
		if (split->bfs_flag == 0)
		{
			orgn->cgp = i;
			return (save);
		}
		ft_fill_path(&path, split->bfs,  split->lwl);
		good[i] = path;
		add_path(good, pfarm, i);//!
		if (worse(save, good, i, aunts))
		{
			orgn->cgp = i;
			return (save);//free all
		}
		ft_pathcp(save, good, i);
		back_to_origin(split, orgn);
		i++;
	}
	orgn->cgp = i;
	return (good);
}