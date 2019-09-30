#include "lemin.h"

int exist_link(t_room *room, int nbr)
{
	int i;

	i = 0;
	while(room->link[i] != -1)
	{
		if (room->link[i] == nbr)
			return(1);
		i++;
	}
	return (0);
}

int search_path(t_room *room)
{
	if (room->link[0] == -1)
	{
		ft_printf("hole in path \n");
		return (-1);
	}
	else if (room->link[1] != -1)
	{
		ft_printf("dup path\n");
		return (-1);
	}
	return (room->link[0]);
}

int search_num_path(t_room *room, int path_numb, t_farm *farm)
{
	int i;
	t_room *link;

	i = 0;
	while (room->link[i] != -1)
	{
		link = farm->arr[room->link[i]];
		if (link->paint_mark == path_numb)
			return (link->pos);
		i++;
	}
	return (-1);
}

void add_path(t_path *good, t_farm *farm , int k)
{
	t_path  path;
	int     i;
	char	queue[100000];
	
	t_room	*room;
	int		new_path[100000];
	t_path	new;
	int		new_size;
	
	path = good[k];
	ft_memset(queue, 0, k);
	queue[k] = 1;
	i = 0;
	printf("\n\n!!!!!!!!!!ITERATION!!!!!!!!!!!!\n%d\n\n", k);
	olya_write_farm(farm);     
	while (i < path.size - 1)
	{
		if (path.bfs[i + 1] > farm->cnt)
			path.bfs[i + 1] -= farm->cnt;
		room = farm->arr[path.bfs[i]];
		if (exist_link(farm->arr[path.bfs[i + 1]], path.bfs[i]) && room->paint_mark != -1) //stay only 1 case
		{
			queue[room->paint_mark] = 1;
			delete_link(farm->arr[path.bfs[i + 1]], path.bfs[i]);
		}
		else
		{
			add_link(room, path.bfs[i + 1]);
			if (farm->arr[path.bfs[i]]->pos != 1)
				farm->arr[path.bfs[i]]->paint_mark = k;
		}
		i++;
	}
	printf("\n");
	olya_write_farm(farm);  
	i = 0;
	while (i < k + 1)
	{
		room = farm->arr[0];
		if (queue[i] == 1)
		{
			new_size = 1;
			room = farm->arr[good[i].bfs[1]];
			//room->paint_mark = i;
			new_path[0] = 0;
			new_path[new_size++] = room->pos;
			while (room->pos != 1 && new_size < 100)
			{
				room = farm->arr[search_path(room)];
				//if (room->pos != 1)
					//room->paint_mark = i;
				new_path[new_size++] = room->pos;
			}
			ft_fill_path(&new, new_path, new_size);
			good[i] = new;
		}
		i++;
	}
}