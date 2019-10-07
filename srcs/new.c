#include "lemin.h"

int init_suurv(t_path *good, t_path *save, t_farm *pfarm, t_farm *split)
{
	int max;
	t_path path;

	max = split->mpw;
	if (!(good = ft_memalloc(sizeof(t_path) * max)))
		exit (-1);
	if (!(save = ft_memalloc(sizeof(t_path) * max)))
		exit (-1);
	ft_fill_path(&path, split->bfs,  split->lwl);
	good[0] = path;
	add_path(good, pfarm, 0, split);
	ft_path_cpy(save, good, 0);
	return (max);
}

t_path *ft_suurballe(t_farm *orgn, t_farm *split, t_farm *pfarm, int aunts)
{
	int i;
	int max;
	t_path  path;
	t_path	*save;
	t_path  *good;

	max = init_suurv(good, save, pfarm, split);
	i = 1;
	while (i < max && i < aunts)
	{
		orgn->cgp = i;
		ft_fill_path(&path, split->bfs,  split->lwl);
		good[i] = path;
		add_path(good, pfarm, i, split);
		all_split(good, i, split);
		ft_bfs(split->arr, split->cnt, split);
		if (worse(save, good, i, aunts) || split->bfs_flag == 0)
		{
			free(good);
			return (save);
		}
		ft_path_cpy(save, good, i);
		back_to_origin(split, orgn);
		i++;
	}
	orgn->cgp = i;
	free(save);
	return (good);
}