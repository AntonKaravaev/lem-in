#include "lemin.h"

void add_link(t_room *room, int new)
{
	int i;

	i = 0;
	while (room->link[i] != -1)
	{
		if (room->link[i] == new)
		{
		//	ft_printf("links already exist\n");
			return ; 
		}
		i++;
	}
	room->link[i++] = new;
	room->link[i] = -1;
}

void change_link(t_room *room, int change, int new)
{
	int i;
	int *link;

	link = room->link;
	i = 0;
	while (link[i] != -1)
	{
		if (link[i] == change)
		{
			link[i] = new;
			return ;
		}
		i++;
	}
//	if (link[i] == -1)
	//	ft_printf("no exist changing links\n");	
}

void delete_link(t_room *room, int del_link)
{
	int i;
	int *link;
	int flag;

	i = 0;
	flag = 0;
	link = room->link;
	while (link[i] != -1)
	{
		if (link[i] == del_link || flag)
		{
			flag = 1;
			link[i]	= link[i + 1];
		}
		i++;
	}
	if (flag == 0)
	{
		//ft_printf("no exist deleting links\n");
	//	return ;
	}
}

int no_duplicate(int room_pos, t_farm *farm)
{
	int *link;

	//or two 


	if (room_pos > farm->cnt)
		return (0);
	link = farm->arr[room_pos + farm->cnt]->link;
	if (link[0] == -1)
		return (1);
	return (0);
}

void split_rev(t_path *path, t_farm *farm)
{
	int i;
	int j;
	t_room *next;
	t_room *room;
	t_room *pr;
	t_room *outing;
//	int n_double_flag;
	//olya_write_dfarm(farm);
	i = path->size - 2;
	while (i > 0)
	{
		room = farm->arr[path->bfs[i]];
		pr = farm->arr[path->bfs[i + 1]];
		next = farm->arr[path->bfs[i - 1]];
	//	n_double_flag = no_duplicate(room->pos, farm);
		j = 0;
		while (room->link[j] != -1)
		{
		//	printf("room->pos = %d, room_link = %d n_dbl = %d\n", room->pos, room->link[j], n_double_flag);
			if (room->link[j] == pr->pos)//ok
			{
				//reverse()
				delete_link(room, room->link[j]);
				add_link(pr, room->pos);
				j--;
			}
			else if (room->link[j] == next->pos)//ok
			{
				delete_link(next, room->pos);
				delete_link(room, next->pos);
				add_link(room, room->pos + farm->cnt);
				add_link(farm->arr[room->pos + farm->cnt], next->pos);
				j--;
				//else
				//	add_link(room, next->pos);
			}
			else //ok
			{
				outing = farm->arr[room->link[j]];
				change_link(outing, room->pos, room->pos + farm->cnt);
				if (outing->paint_mark != -1)
				{
					//ft_printf(" room = %d, outing = %d\n", room->pos, outing->pos);
					change_link(room, outing->pos, outing->pos + farm->cnt);
				}
			}
			j++;
		}
		//add_link(farm->arr[path->bfs[i + 1]], room->pos);
		i--;
	}
}