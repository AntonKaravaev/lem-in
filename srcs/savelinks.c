/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savelinks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:21:17 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/05 21:58:42 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_savelinks(char **line, t_map *map)
{
	ft_printf("q_rooms = %d\n", map->q_rooms);
	if (map->lf == 0)
		map->lf++;
	if (*line && *line[0] != '-' && ft_strchr(*line, 45) != NULL)
	{
		map->str = ft_strsplit(*line, '-');
		ft_printf("map->str[0] = %s\n", map->str[0]);
		ft_printf("map->str[1] %s\n", map->str[1]);
		ft_printf("map->str[2] %s\n", map->str[2]);
		if (map->str[0] != NULL && map->str[1] != NULL && map->str[2] == NULL)
		{
			ft_str2del(&map->str);
		}
		else
			ft_linkserror();
	}
	else
		ft_linkserror();
}
