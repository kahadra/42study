/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:46:27 by chpark            #+#    #+#             */
/*   Updated: 2022/04/28 14:46:29 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

static double	ft_percent(int start, int end, int current)
{
	double	plac;
	double	dist;

	plac = current - start;
	dist = end - start;
	if (dist == 0)
		return (1.0);
	return ((plac / dist));
}

static unsigned int	ft_get_light(int start, int end, double percent)
{
	return ((unsigned int)((1 - percent) * start + percent * end));
}

unsigned int	ft_get_color(t_data *data, int x, int y)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	double			percent;

	if (data->cur_c == data->end_c)
		return (data->cur_c + data->color);
	if (x > y)
		percent = ft_percent(data->st_x, data->end_x, data->cur_x);
	else
		percent = ft_percent(data->st_y, data->end_y, data->cur_y);
	r = ft_get_light((data->st_c >> 16) & 0xFF, (data->end_c >> 16)
			& 0xFF, percent);
	g = ft_get_light((data->st_c >> 8) & 0xFF, (data->end_c >> 8)
			& 0xFF, percent);
	b = ft_get_light(data->st_c & 0xFF, data->end_c & 0xFF, percent);
	return (((r << 16) | (g << 8) | b) + data->color);
}

unsigned int	ft_get_default_color(int z, t_data *data)
{
	double	percent;

	percent = ft_percent(data->minz, data->maxz, z);
	if (percent < 0.2)
		return (COLOR_DEEP);
	else if (percent < 0.4)
		return (COLOR_RED);
	else if (percent < 0.6)
		return (COLOR_ZERO);
	else if (percent < 0.8)
		return (COLOR_WHITE);
	else
		return (COLOR_UP);
}

void	MAX_MIN_data(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->z[i][j] < data->minz)
				data->minz = data->z[i][j];
			if (data->z[i][j] > data->maxz)
				data->maxz = data->z[i][j];
			j++;
		}
		i++;
	}
}