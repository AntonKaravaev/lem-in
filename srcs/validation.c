/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:04:02 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/03 14:44:14 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		ft_analyse_line(t_map *map, char **line)
{
	if (*(*line) == '#' && ft_strequ(*line, "##start\0") == 0
		&& ft_strequ(*line, "##end\0") == 0)
		return (1);
	else if (map->s == 0 && map->e == 0 && ft_strequ(*line, "##start\0" ) == 1
		&& map->ants > 0)
	{
		map->s = 1;
		return (1);
	}
	else if (map->s == 1 && map->e == 0 && ft_strequ(*line, "##end\0") == 1
		&& map->ants > 0)
	{
		map->e = 1;
		return (1);
	}
	else if ((*(*line) == ' ' || *(*line) == '\n' || *(*line) == '\t'
		|| *(*line) == '-') || ((map->s == 1 || map->e == 1)
		&& ft_strequ(*line, "##start\0") == 1) || ((map->e == 1 || map->s == 0)
		&& ft_strequ(*line, "##end\0") == 1)
		|| (ft_strequ(*line, "##start\0") == 1 && map->ants <= 0)
		|| (ft_strequ(*line, "##end\0") == 1 && map->ants <= 0))
		return (-1);
	return (0);
}

static void		ft_find_amount_of_ants(char **line , t_map *map)
{
	char **str;

	str = NULL;
	str = ft_strsplit(*line, ' ');
	if (str[1] != NULL)
	{
		write(1, "Error(ants)\n", 12);
		exit(-1);
	}
	else
	{
		map->ants = ft_atoilemin(str[0]);
		ft_strdel(str);
	}
	ft_strdel(line);
}

static void		ft_save_inf(char **line, t_list *rooms, t_map *map)
{
	(void)rooms;
	if (map->ants == 0)
		ft_find_amount_of_ants(line, map);
	ft_printf("map->ants = %d\n", map->ants);
}


void 			ft_validation(t_list *rooms, t_map *map)
{
	char	*line;

	line = NULL;
	while (1)
	{
		// еще нужно зафришить список rooms
		if (get_next_line(0, &line) < 0)
		{
			ft_strdel(&line);
			write(2, "READ ERROR(GNL)\n", 16);
			exit (-1);
		}
		else if (line == NULL)
			break;
		else if (ft_analyse_line(map, &line) == 1)
		{
			ft_strdel(&line);
			continue;
		}
		else if (ft_analyse_line(map, &line) == -1)
		{
			ft_strdel(&line);
			write(2, "READ ERROR(INPUT)\n", 18);
			exit (-1);
		}
		else if (ft_analyse_line(map, &line) == 0)
			ft_save_inf(&line, rooms, map);
	}
	ft_strdel(&line);
}
