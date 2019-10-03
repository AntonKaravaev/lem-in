/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 13:55:33 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/03 01:04:40 by crenly-b         ###   ########.fr       */
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
	int		paint_mark; // -1, Special for Olya :) 
	int 	*link; //Инициализировать N , конец -1
}				t_room;

typedef struct	s_path
{
	int		a_h; // ants_here
	int		size; 
	int		bfs[10000];
	int		*p; // print_massive
}				t_path;

typedef struct	s_map
{
	t_list	*rooms;
	t_room	*new_room;
	int		**edge_table;
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
}				t_map;

typedef struct s_farm
{
	// все выделяется один раз, молочится тоже будет один раз в самом конце!!!
	int		cnt;
	t_room	**arr;
	int 	**wl; // BFS potensial ways
	int 	*line; // for finding bfs
	int		*bfs; // current good bfs ||size???????????????????
	int		bfs_flag; // do we have bfs or not.
	int		mpw; // minimal_potensial_ways! Be careful it rewrites every time if you use bfs fucction
	int 	lwl; // levels_of_rooms
	int		p; //iterator like global param
	int		cgp; //count good paths
} t_farm;


int			main(int argc, char *argv[]);       
void		ft_validation(t_map *map, t_farm *farm);
int			ft_atoilemin(char *s);
void		ft_atoicoor(char *s);
void		ft_find_start_room(char **line, t_map *map);
void		ft_find_end_room(char **line, t_map *map);
void		ft_find_curr_room(char **line, t_map *map);
void		ft_savelinks(char **line, t_map *map, t_farm *farm);
void		ft_fiil_in_links(t_map *map, t_farm *farm);
void		ft_str_of_names(t_map *map);
void		ft_lem_error(const char *err, char **line);
void		ft_linkserror();
void		ft_input_error();
void		ft_cant_find_way_error();
void		ft_solution(t_map *map, t_farm *farm);
void		ft_str_of_names(t_map *map);
void		ft_create_ways_lines(t_farm *farm);
int			ft_fiil_in_ways_lines(t_farm *farm);
void		ft_create_line(t_farm *farm);
void		ft_fiil_in_line(t_farm *farm);
void		ft_farm_initial(t_farm *farm, t_map *map);
void		ft_print_BFS_potensial(t_farm *farm);
void		ft_print_BFS(t_farm *farm);
void		ft_print_temp_line(t_farm *farm);
void        ft_print_way1(t_map *map, t_farm *farm);
void		ft_bfs(t_room **ar_r, int q_rooms, t_farm *farm);
void		ft_check_and_right_to_wl(t_farm *farm, int number, int pos);
void		ft_bfs_finder(t_farm *farm);

void		split_rev(t_path *path, t_farm *farm);
t_path		*ft_suurballe(t_farm *orgn, t_farm *split, t_farm *pfarm, int aunts);
void		olya_write_farm(t_farm *farm);
void		olya_write_dfarm(t_farm *farm);
void		add_path(t_path *good, t_farm *farm , int k);
void		add_link(t_room *room, int new);
void		change_link(t_room *room, int change, int new);
void		delete_link(t_room *room, int del_link);
void		ft_fill_path(t_path *path, int *bfs, int size);
void		init_split(t_farm *orgn, t_farm *new);
void		olya_write_path(t_path path);
void		olya_write_good(t_path *good, int cgp);
void		ft_clean_links(t_farm *farm);
void		ft_dup_clear_farm(t_farm *pfarm, int n);
void		olya_write_name_path(t_path *save, int k, t_farm *orgn);

void		write_room(t_room *room);
void        ft_print_result(t_path *ans, t_map *map, int cgp, int ants);

#endif
