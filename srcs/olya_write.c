#include "lemin.h"
#include "stdio.h"

void write_room(t_room *room)
{
    int i;

    printf("name = %s, pos = %d color = %d line ", room->name, room->pos, room->paint_mark);
    i = 0;
    while (room->link[i] != -1)
    {
        printf("%d ", room->link[i]);
        i++;
    }
    printf("\n");
}


void olya_write_dfarm(t_farm *farm)
{
    int i;

    i = 0;
    while (i < farm->cnt * 2)
    {
        write_room(farm->arr[i]);
        i++;
    }
}
void olya_write_good(t_path *good, int cgp)
{
    int i;

    i = 0;
    while (i < cgp)
    {
        olya_write_path(good[i]);
        i++;
    }
    ft_printf("\n");
}
void olya_write_path(t_path path)
{
    int i;

    i = 0;
    while (i < path.size)
    {
        ft_printf(" %d ", path.bfs[i]);
        i++;
    }
    ft_printf("\n");
}

void olya_write_farm(t_farm *farm)
{
    int i;

    i = 0;
    while (i < farm->cnt)
    {
        write_room(farm->arr[i]);
        i++;
    }
}