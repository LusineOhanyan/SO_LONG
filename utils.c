/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:10:58 by lohanyan          #+#    #+#             */
/*   Updated: 2022/09/18 12:39:04 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ending(t_vars *vars)
{
	free_map(vars->map);
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
	return (0);
}

void	free_map(char **map)
{
	int		i;

	i = 0;
	while (map && map[i])
	{
		free (map[i]);
		i++;
	}
	free(map);
}

void	end(char **map)
{
	free_map(map);
	exit (0);
}
