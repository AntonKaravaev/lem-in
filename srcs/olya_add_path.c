#include "lemin.h"

/*


void add_path(t_path *good, t_farm *farm , int k)
{
	int i;
	t_room *room;
	t_path path;
	char queue[100000]; //max_path
	int j;
	int p;
	int	new_path[100000];
	t_path new;
	//закрасим k
	i = 1;
	path = good[k];
	ft_memset(queue, 0, k);
	queue[k] = 1;
	while (i < path.size - 1)
	{
		if (path.bfs[i] >= farm->cnt)//а если подряд идут?
			path.bfs[i] -= farm->cnt;
		room = farm->arr[path.bfs[i]];
		if (room->paint_mark != -1)
		{
			//if ((room->paint_mark == farm->arr[path.bfs[i + 1]]->path) - always
			queue[room->paint_mark] = 1;
			i++;
			delete_link(room, path.bfs[i]);
			room = farm->arr[path.bfs[i]];
			//room->paint_mark = k;
			delete_link(room, path.bfs[i - 1]);
		}
		else
			room->paint_mark = k;
		i++;		
	}
//	ft_printf("in add \n");
//	olya_write_farm(farm);
	//end окраски
	p = 0;
	while (p < k + 1)
	{
		room = farm->arr[0]; 
		if (queue[p] == 1)
		{
			j = 1;
			room = farm->arr[search_num_path(room, p, farm)];
			new_path[0] = 0;
	//		ft_printf("A ");
			new_path[j++] = room->pos;
	//		ft_printf("%s ", room->name);
			while (room->pos != 1 && j < 100)
			{
				room = farm->arr[search_path(room, farm, new_path[j - 2])];
				//ft_printf("%s ", room->name);
				new_path[j++] = room->pos;
			}
			ft_fill_path(&new, new_path, j);
		//	ft_printf("\n");
			good[p] = new;

			//good[] ПЕРЕПИСАТЬ НОВОЕ 
		}
		p++;
	}
}
*/