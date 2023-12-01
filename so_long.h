/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:32:30 by lohanyan          #+#    #+#             */
/*   Updated: 2022/09/17 16:13:51 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_vars
{
	int		width;
	int		height;
	void	*mlx;
	void	*win;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	int		fd;
	char	**map;
}			t_vars;

int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
int		ft_count(char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**ft_split(char *s, char c);
char	*ft_strchr(char *s, int c);
char	**parsing(int fd);
int		count_height(char **map);
int		count_width(char **map);
int		player(t_vars *vars, int c);
void	move_right(t_vars *vars, int *count2);
void	move_left(t_vars *vars, int *count2);
void	move_up(t_vars *vars, int *count2);
void	move_down(t_vars *vars, int *count2);
int		count(t_vars *vars);
void	ft_putnbr(int nb);
void	free_map(char **map);
void	checking(char **map);
int		error3(char **map, char c);
int		error2(char **map);
int		error1(char **map);
int		error(char **map);
int		error4(char **map);
int		ending(t_vars *vars);
void	end(char **map);

#endif
