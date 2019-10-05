/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 13:53:48 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/05 15:05:20 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				main(int argc, char *argv[])
{
	t_map	map;
	t_farm	farm;

	(void)argc;
	(void)argv;
	ft_mapinitial(&map);
	ft_farm_initial(&farm, &map);
	ft_validation(&map, &farm);
	if (map.ants != 0 && map.s != 0 && map.e != 0 && map.q_rooms != 0
		&& map.sf != 0 && map.ef != 0 && map.lf != 0)
		ft_solution(&map, &farm);
	else
		ft_input_error();
	//ft_free_whats_needs(&map);
	return (0);
}
