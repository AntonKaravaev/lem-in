/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 13:55:33 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/11 17:16:35 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/includes/libft.h"

typedef struct	s_room
{
	char	*name;
	int		x;
	int		y;
	int		pos;
}				t_room;

typedef struct	s_map
{
	t_list	*rooms;
	t_room	*new_room;
	int		**edge_table;
	int		**temp_et;
	int		**ways;
	int		*temp_line;
	char	**str;
	int		q_rooms; // quantity of rooms
	int		ants;
	int		s; // start
	int		e; // end
	int		lf; // ants in a start room
	int		sf;
	int		ef; // ants in an end room
	int		temp_x;
	int		temp_y;
	int		max_x;
	int		max_y;
	int		ls_counter;
	int		bfs;
	int		*bfs_str;
}				t_map;

int			main(int argc, char *argv[]);
void		ft_validation(t_map *map);
int			ft_atoilemin(char *s);
void		ft_atoicoor(char *s);
void		ft_find_start_room(char **line, t_map *map);
void		ft_find_end_room(char **line, t_map *map);
void		ft_find_curr_room(char **line, t_map *map);
void		ft_savelinks(char **line, t_map *map);
void		ft_solution(t_map *map);
void		ft_str_of_names(t_map *map);
void		ft_lem_error(const char *err, char **line);
void		ft_linkserror();
void		ft_input_error();
void		ft_cant_find_way_error();
void		ft_printlinkstable(t_map *map);
void		ft_print_BFS(t_map *map);
void 		ft_find_bfs(t_map *map);
void    	ft_print_way1(t_map *map);
void		ft_let_ants_move(t_map *map);
void		ft_create_temp_line(t_map *map);
void		ft_create_str_ways(t_map *map);
void        ft_create_way_line(t_map *map, int quantity);


#endif
