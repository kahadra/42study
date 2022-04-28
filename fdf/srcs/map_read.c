/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:24:06 by chpark            #+#    #+#             */
/*   Updated: 2022/04/22 13:50:05 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

static size_t	get_rows(char *file)
{
	size_t	fd;
	size_t	rows;

	fd = open(file, O_RDONLY, 0);
	rows = 0;
	while (get_next_line(fd))
		rows++;
	close(fd);
	return (rows);
}

static	size_t	get_colums(char *file)
{
	size_t	fd;
	size_t	colums;
	size_t	count;
	char	*str;

	fd = open(file, O_RDONLY, 0);
	str = get_next_line(fd);
	count = count_s(str, ' ');
	colums = count + 1;
	close(fd);
	return (colums);
}

static char	**map_read(char *file)
{
	size_t	i;
	size_t	rows;
	size_t	colums;
	char	**map;
	int		fd;

	fd = open(file, O_RDONLY, 0);
	rows = get_rows(file);
	colums = get_colums(file);
	map = (char **)malloc(sizeof(char) * ((rows + 1) * colums));
	i = 0;
	while (i < rows)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

static int	*get_value(char *line, t_data *data)
{
	int		i;
	int		len;
	int		*value;
	char	**str;
	char	**color;

	i = 0;
	str = ft_split(line, ' ');
	while (!str[i])
		i++;
	len = i;
	i = 0;
	value = (int *)malloc(sizeof(int) * len);
	while (!str[i])
	{
		if (ft_strchr(str[i], ','))
		{
			color = ft_split(str[i], ',');
			free(str[i]);
			value[i] = ft_atoi(color[0]);
			data->color = ft_atoi(color[1]);
			free(color);
			color = NULL;
		}
		else
		{
			value[i] = ft_atoi(str[i]);
			free(str[i]);
		}
		i++;
	}
	free(str);
	str = NULL;
	return (value);
}

void	xyz_init(t_data *data, char *file)
{
	char	**map;
	int		**z;
	int		i;

	i = 0;
	data->x = get_colums(file);
	data->y = get_rows(file);
	map = map_read(file);
	z = (int **)malloc(sizeof(int) * (data->x * data->y));
	while (!map[i])
	{
		z[i] = get_value(map[i], data);
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
	data->z = z;
}
