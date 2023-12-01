/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:52:30 by lohanyan          #+#    #+#             */
/*   Updated: 2022/09/18 13:19:47 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	error(char	**map)
{
	int	j;
	int	tmp;

	j = 0;
	while (map[j] != '\0')
	{
		tmp = ft_strlen(map[j]);
		j++;
		if (map[j] == NULL)
			break ;
		if (tmp != ft_strlen(map[j]))
			return (0);
	}
	return (1);
}

int	error1(char **map)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (map[++j])
	{
		while (map[j][++i])
		{
			if (map[0][i] != '1' || map[j][0] != '1')
				return (0);
			else if (map[j][i + 1] == '\0' && map[j][i] != '1')
				return (0);
			if (map[j + 1] == NULL)
			{
				i = -1;
				while (map[j][++i])
					if (map[j][i] != '1')
						return (0);
			}
		}
		i = -1;
	}
	return (1);
}

int	error2(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] != '1' && map[j][i] != '0' && map[j][i] != 'c'
					&& map[j][i] != 'e' && map[j][i] != 'p')
				return (0);
				i++;
		}
		j++;
		i = 0;
	}
	return (1);
}

int	error3(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == c)
				count++;
			i++;
		}
		j++;
		i = 0;
	}
	return (count);
}

int	error4(char **map)
{
	if (error3(map, 'p') != 1)
		return (0);
	if (error3(map, 'c') < 1)
		return (0);
	if (error3(map, 'e') < 1)
		return (0);
	return (1);
}
