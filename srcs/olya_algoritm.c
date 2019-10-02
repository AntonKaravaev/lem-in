#include "lemin.h"

/*
void init_pure_farm(t_farm *new, int size)
{
	t_room	**array_rooms;
	t_room	*room;
	int		i;
	int		j;
	if (!(array_rooms = malloc(sizeof(t_room) * size)))
		exit (-1);
	i = 0;
	while (i < size)
	{
		if (!(room = malloc(sizeof(t_room))))
			exit(-1);
		if (!(room->link = malloc(sizeof(int) * size)))
			exit (-1);
		j = -1;
		while (++j < size)
			room->link[j] = -1;
		i++;
	}
}
*/
//


void add_path(t_path *good, t_path path, t_farm *farm, int n, int max_path) //n - number path
{
	t_stack stack;//можно маллочить длины max_path/ нужен стек!
	int	new[3000];
	int color;//закрашивает
	int way_now;
	int room_numb;
	t_room *room;
	int i;
	int j;

	if (!(stack.array = malloc(sizeof(int) * max_path)))
		exit(-1);
	stack.size = max_path;
	stack.start = max_path;
	push(&stack, n);
	room = farm->array_room[0];
	way_now = color;
	new[0] = room->pos;// = 0 
	while (stack.size != stack.start)
	{
		color = pop(&stack);

		room_numb = search_link(room, way_now);
		room = 
		j = 1;
		while (room->pos != 1)
		{
			if (way_now == n)
			{
				if ()
			}
			else
			{
				
			}
			
			room_numb = search_link(room, way_now);
		}
		
	}
}

void algoritm(t_farm *origin)
{
	t_path *good; //твой t_goodway
	t_path *tmp;
	t_path path;
	int i;
	int max_path;//число возможноых путей
	
	t_farm split;

	split = farm_dup(origin);
	//!!!!!!!!!!!!!!!
	//initial t_room **array_room by size 2n!
	//маллочить t_path *good; //твой t_goodway
	t_path *tmp;
	path = bfs(split, &max_path);
	good[0] = path;
	max_path = 10;
	good = malloc(sizeof(t_path) * (max_path));
	while (i < max_path)
	{
		split_rev(path, split);
		path = bfs(split, &max_path);
		add_path(tmp, path, origin, i);
		if (coust tmp > coust good)
			return (good);
		//перекопировать
		//good = tmp;
		i++;
		//
		//
		//
	}
}