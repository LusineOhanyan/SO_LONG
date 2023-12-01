/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:37:37 by lohanyan          #+#    #+#             */
/*   Updated: 2022/09/18 12:26:04 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count(t_vars *vars)
{
	char	**map;
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	map = vars->map;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == 'c')
				count++;
			i++;
		}
		j++;
		i = 0;
	}
	return (count);
}

int	player(t_vars *vars, int c)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = vars->map;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == 'p')
			{
				if (c == 'x')
					return (i);
				else
					return (j);
			}
			i++;
		}
			j++;
			i = 0;
	}
	return (0);
}
