#include "lemin.h"

void add_link(t_room *room, int new)
{
	int i;

	i = 0;
	while (room->link[i] != -1)
	{
		if (room->link[i] == new)
		{
			ft_printf("links already exist\n");
			return ; 
		}
		i++;
	}
	room->link[i] = new;
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
	if (link[i] == -1)
		ft_printf("no exist changing links\n");	
}

void delete_link(t_room *room, int del_link)
{
	int i;
	int *link;
	int deleting_index;

	i = 0;
	deleting_index = -1;
	link = room->link;
	while (link[i] != -1)
	{
		if (link[i] == del_link)
			deleting_index = i;
		i++;
	}
	if (deleting_index < 0)
	{
		ft_printf("no exist deleting links\n");
		return ;
	}
	link[deleting_index] = link[i - 1];
	link[i - 1] = -1;
}

int no_duplicate(int room_pos, t_farm *farm)
{
	int *link;

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

	i = path->size - 2;
	while (i > 0)
	{
		room = farm->arr[path->bfs[i]];
		pr = farm->arr[path->bfs[i + 1]];
		next = farm->arr[path->bfs[i - 1]];
		j = 0;
		while (room->link[j] != -1)
		{
			if (room->link[j] == pr->pos)//ok
			{
				//reverse()
				delete_link(room, room->link[j]);
				add_link(pr, room->pos);
			}
			else if (room->link[j] == next->pos)//ok
			{
				delete_link(next, room->pos);
				if (no_duplicate(next->pos, farm))
				{
					delete_link(room, next->pos);
					add_link(room, room->pos + farm->cnt);
					add_link(farm->arr[room->pos + farm->cnt], next->pos);
				}
				//else
				//	add_link(room, next->pos);
			}
			else if (no_duplicate(room->pos, farm))//ok
			{
				outing = farm->arr[room->link[j]];
				change_link(outing, room->pos, room->pos + farm->cnt);
			}
			j++;	
		}
		olya_write_dfarm(farm);
		printf("\n");
		//add_link(farm->arr[path->bfs[i + 1]], room->pos);
		i--;
	}
}