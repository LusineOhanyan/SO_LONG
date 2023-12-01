/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:51:45 by lohanyan          #+#    #+#             */
/*   Updated: 2022/09/18 13:17:39 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	moving(int key, t_vars *vars)
{
	static int	count1;

	if (key == 2)
		move_right (vars, &count1);
	if (key == 0)
		move_left (vars, &count1);
	if (key == 13)
		move_up (vars, &count1);
	if (key == 1)
		move_down (vars, &count1);
	if (key == 53)
	{
		free_map(vars->map);
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0);
	}
	return (0);
}

void	init_image(t_vars *vars)
{
	int	x;
	int	y;

	vars->img1 = mlx_xpm_file_to_image
		(vars->mlx, "./images/wall.xpm", &x, &y);
	vars->img2 = mlx_xpm_file_to_image
		(vars->mlx, "./images/back.xpm", &x, &y);
	vars->img3 = mlx_xpm_file_to_image
		(vars->mlx, "./images/jerry.xpm", &x, &y);
	vars->img4 = mlx_xpm_file_to_image
		(vars->mlx, "./images/exit.xpm", &x, &y);
	vars->img5 = mlx_xpm_file_to_image
		(vars->mlx, "./images/cheese.xpm", &x, &y);
}

void	put_images_to_win(t_vars vars, char **map, int j, int i)
{
	if (map[j][i] == '1')
		mlx_put_image_to_window
			(vars.mlx, vars.win, vars.img1, i * 64, j * 64);
	else if (map[j][i] == '0')
		mlx_put_image_to_window
			(vars.mlx, vars.win, vars.img2, i * 64, j * 64);
	else if (map[j][i] == 'p')
	{
		mlx_put_image_to_window
		(vars.mlx, vars.win, vars.img2, i * 64, j * 64);
		mlx_put_image_to_window
			(vars.mlx, vars.win, vars.img3, i * 64, j * 64);
	}
	else if (map[j][i] == 'e')
		mlx_put_image_to_window(vars.mlx, vars.win, vars.img4, i * 64, j * 64);
	else if (map[j][i] == 'c')
	{
		mlx_put_image_to_window
			(vars.mlx, vars.win, vars.img2, i * 64, j * 64);
		mlx_put_image_to_window
			(vars.mlx, vars.win, vars.img5, i * 64, j * 64);
	}
}

void	put_images(t_vars vars)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = vars.map;
	while (map[j])
	{
		while (map[j][i])
		{
			put_images_to_win(vars, map, j, i);
			i++;
		}
		j++;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	int		x;
	int		y;
	t_vars	vars;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			exit(EXIT_FAILURE);
		vars.map = parsing(fd);
		checking(vars.map);
		x = count_height(vars.map);
		y = count_width(vars.map);
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, x * 64, y * 64, "so_long");
		init_image(&vars);
		mlx_hook(vars.win, 17, 0, ending, &vars);
		mlx_key_hook(vars.win, moving, &vars);
		put_images(vars);
		mlx_loop(vars.mlx);
	}
	else
		write(1, "Argument error\n", 15);
	return (0);
}
