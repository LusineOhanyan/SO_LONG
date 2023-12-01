/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:55:43 by lohanyan          #+#    #+#             */
/*   Updated: 2022/09/17 16:14:03 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*string;
	size_t			lenstr;
	size_t			first;
	unsigned int	index;

	if (!s)
		return (0);
	lenstr = ft_strlen(s);
	first = ft_strlen(s + start);
	if (first < len)
		len = first;
	string = malloc(len + 1);
	index = 0;
	while (index < len && start + index < (unsigned int)lenstr)
	{
		string[index] = s[start + index];
		index++;
	}
	string[index] = '\0';
	return (string);
}

char	**ft_split(char *s, char c)
{
	char	**str;
	int		i;
	size_t	skizb;
	size_t	avart;

	str = (char **)malloc ((ft_count(s, c) + 1) * sizeof(char *));
	if (!s || !str)
		return (0);
	i = 0;
	skizb = 0;
	avart = 0;
	while (i < ft_count(s, c))
	{
		while (s[skizb] == c)
			skizb++;
		avart = skizb;
		while (s[avart] != c && s[avart])
			avart++;
		str[i] = ft_substr(s + skizb, 0, (avart - skizb));
		skizb = avart;
		i++;
	}
	str[i] = 0;
	return (str);
}
