/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sup_lem_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:43:54 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/26 23:46:28 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_print_BFS_potensial(t_farm *farm)
{
	int		i;
	int		j;

	i = -1;
	ft_printf("|0| |1| |2|  |3|  |4| |5|\n");
	ft_printf("_________________________\n");
	while (++i < farm->lwl)
	{
		j = -1;
		while (farm->wl[i][++j] != -1)
		{
			ft_printf("|%d| ", farm->wl[i][j]);
		}
		ft_printf("|%d|", farm->wl[i][j]);
		ft_printf("\n");
	}
	ft_printf("\n");
}

void		ft_print_BFS(t_farm *farm)
{
	int		i;

	i = -1;
	while (farm->bfs[++i] != -1)
		ft_printf("%d ", farm->bfs[i]);
	ft_printf("\n");
	ft_printf("\n");
}


void		ft_print_temp_line(t_farm *farm)
{
	int		i;

	i = -1;
	while (farm->line[++i] != -1)
		ft_printf("%d ", farm->line[i]);
	ft_printf("\n");
	ft_printf("\n");
}