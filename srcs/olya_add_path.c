#include "lemin.h"


int search_path(t_room *room, t_farm *farm)
{
	int i;
	t_room *link;

	i = 0;
	while (room->link[i] != -1)
	{
		link = farm->array_room[room->link[i]];
		if (link->path != -1 || link->pos == 1)
			return (link->pos);
		i++;
	}
	return (-1);
}

int search_num_path(t_room *room, int path_numb, t_farm *farm)
{
	int i;
	t_room *link;

	i = 0;
	while (room->link[i] != -1)
	{
		link = farm->array_room[room->link[i]];
		if (link->path == path_numb)
			return (link->pos);
		i++;
	}
	return (-1);
}

void add_path(t_path *good, t_farm *farm , int k, int max_path)
{
	int i;
	t_room *room;
	t_path path;
	char queue[100000]; //max_path
	int j;
	int new_path;
	int length_new_path;
	int index_room;
	int p;
	t_path new;

	//закрасим k
	i = 1;
	path = good[k];
	queue[k] = 1;
	while (i < path.length - 1)
	{
		if (path.bfs_str[i] >= farm->count_room)//а если подряд идут?
			path.bfs_str[i] -= farm->count_room;
		room = farm->array_room[path.bfs_str[i]];
		if (room->path != -1)
		{
			//if ((room->path == farm->array_room[path.bfs_str[i + 1]]->path) - always
			queue[room->path] = 1;
			i++;
			delete_link(room, path.bfs_str[i]);
			room = farm->array_room[path.bfs_str[i]];
			delete_link(room, path.bfs_str[i - 1]);
		}
		else
			room->path = k;
		i++;		
	}
	//end окраски
	p = 0;
	while (p < max_path)
	{
		if (queue[p] != 0)
		{
			j = 1;
			room = farm->array_room[search_num_path(room, p, farm)];
			queue[0] = 0;
			queue[j] = room->pos;
			while (room->pos != 1)
			{
				room = farm->array_room[search_path(room, farm)];
				queue[j] = room->pos;
				j++;
			}
			//good[] ПЕРЕПИСАТЬ НОВОЕ 
		}
		p++;
	}
}