/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:44:45 by lohanyan          #+#    #+#             */
/*   Updated: 2022/09/18 13:18:45 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

char	**parsing(int fd)
{
	char	buf[6];
	char	*tmp;
	int		i;
	char	**map;

	i = 1;
	tmp = NULL;
	if (fd < 0)
		return (NULL);
	while (i > 0)
	{
		i = read(fd, buf, 5);
		buf[i] = '\0';
		if (i == 0 && tmp == NULL)
			return (0);
		if (tmp == NULL)
			tmp = ft_strdup(buf);
		else
			tmp = ft_strjoin(tmp, buf);
	}
	map = ft_split(tmp, '\n');
	free(tmp);
	return (map);
}

int	count_height(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j][i])
	{
		i++;
	}
	return (i);
}

int	count_width(char **map)
{
	int	j;

	j = 0;
	while (map[j])
		j++;
	return (j);
}

void	checking(char **map)
{
	if (!error(map) || !error1(map) || !error2(map) || !error4(map))
	{
		write(1, "error\n", 6);
		free_map(map);
		exit(0);
	}
}
