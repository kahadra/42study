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

#include "fdf.h"

static size_t	get_rows(char *file)
{
	size_t	fd;
	size_t	rows;

	fd = open(file, O_RDONLY, 0);
	rows = 0;
	while (get_next_lind(fd))
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
	count = count_s(str, " ");
	colums = count + 2;
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
	map = (char **)malloc(sizeof(char) * ((rows + 2) * colums));
	i = 0;
	while (i < rows)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (map);
}

static int	*get_value(char *line, t_data *data)
{
	int	i;
	int	*value;
	int	**str;
	int	**color;

	i = 0;
	str = ft_split(line, ' ');
	while (str[i] != '\0')
	{
		if (ft_strchr(str[i], ','))
		{
			color = ft_split(str[i], ',');
			value[i] = ft_atoi(color[0]);
			data->color = color[1];
		}
		else
			value[i] = ft_atoi(str[i]);
	}
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
	while (map[i] != '\0')
	{
		z[i] = get_value(map[i], data);
		i++;
	}
	data->z = z;
}
