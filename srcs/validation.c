/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:04:02 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/04 19:41:58 by crenly-b         ###   ########.fr       */
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
		ft_putstr_fd("Error(ants)\n", 2);
		exit(-1);
	}
	else
	{
		map->ants = ft_atoilemin(str[0]);
		ft_strdel(str);
	}
}

static void		ft_save_inf(char **line, t_map *map)
{
	if (map->ants == 0)
		ft_find_amount_of_ants(line, map);
	else if (map->s == 0)
	{
		write(2, "READ ERROR(INPUT)\n", 18);
		exit (-1);
	}
	else if (map->s == 1 && map->str == NULL && map->e == 0)
		ft_find_start_room(line, map);
	else if (map->s == 1 && map->e == 0 && map->str != NULL)
	{
		write(2, "READ ERROR(INPUT)\n", 18);
		exit (-1);
	}
	// else if (map->s == 1 && map->e == 1)
	// {
	// 	if ((ft_strchr(*line, 45)) == NULL)
	// 		ft_find_room(line, map);
	// }
}

static void		ft_validation_sup1(t_map *map, int *gnl_param, char **line)
{
	if (*line == NULL)
	{
		write(2, "READ ERROR(GNL)\n", 16);
		exit (-1);
	}
	else if ((*gnl_param = ft_analyse_line(map, line)) == 1)
		return ;
	else if (*gnl_param == -1)
	{
		write(2, "READ ERROR(INPUT)\n", 18);
		exit (-1);
	}
	else if (*gnl_param == 0)
		ft_save_inf(line, map);
}

void 			ft_validation(t_map *map)
{
	char	*line;
	int		gnl_number;

	line = NULL;
	gnl_number = 0;
	while (1)
	{
		if ((gnl_number = get_next_line(0, &line)) < 0)
		{
			write(2, "READ ERROR(GNL)\n", 16);
			exit (-1);
		}
		else if (gnl_number == 0) // написать функцию проверка корректности если конец файла
			break;
		else
			ft_validation_sup1(map, &gnl_number, &line);
		ft_strdel(&line);
	}
}
