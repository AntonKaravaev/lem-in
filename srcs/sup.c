#include "lemin.h"

void add_link(t_room *room, int new)
{
	int i;

	i = 0;
	while (room->link[i] != -1)
	{
		if (room->link[i] == new)
			return ; 
		i++;
	}
	room->link[i++] = new;
	room->link[i] = -1;
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
		ft_printf("room pos = %d link0 = %d link1 = %d \n", room->pos, room->link[0], room->link[1]);
		ft_printf("dup path\n");
		return (-1);
	}
	return (room->link[0]);
}