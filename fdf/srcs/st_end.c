/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:12:05 by chpark            #+#    #+#             */
/*   Updated: 2022/04/28 14:12:26 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

static void	ft_rot_x(int *y, int *z, double alpha)
{
	int	temp_y;

	temp_y = *y;
	*y = temp_y * cos(alpha) + *z * sin(alpha);
	*z = -temp_y * sin(alpha) + *z * cos(alpha);
}

static void	ft_rot_y(int *x, int *z, double beta)
{
	int	temp_x;

	temp_x = *x;
	*x = temp_x * cos(beta) + *z * sin(beta);
	*z = -temp_x * sin(beta) + *z * cos(beta);
}

static void	ft_rot_z(int *x, int *y, double gamma, t_data *data)
{
	int	temp_x;
	int	temp_y;

	temp_x = *x;
	temp_y = *y;
	*x = temp_x * cos(gamma) - temp_y * sin(gamma);
	*y = temp_x * sin(gamma) + temp_y * cos(gamma);
	if (data->projection == 1)
		ft_parallel(data);
}

void	ft_st(t_data *data, int x, int y)
{
	data->st_x = x;
	data->st_y = y;
	data->st_z = data->z[y][x];
	data->st_c = ft_get_default_color(data->st_z, data);
	data->st_x *= data->zoom;
	data->st_y *= data->zoom;
	data->st_z *= data->zoom / data->z_corr;
	data->st_x -= (data->width * data->zoom) / 2;
	data->st_y -= (data->height * data->zoom) / 2;
	ft_rot_x(&data->st_y, &data->st_z, data->alpha);
	ft_rot_y(&data->st_x, &data->st_z, data->beta);
	ft_rot_z(&data->st_x, &data->st_y, data->gamma, data);
	if (data->projection == 0)
		ft_isometric(data);
	data->st_x += WIDTH / 2 + data->x_shift;
	data->st_y += (HEIGHT + data->height * data->zoom) / 2 + data->y_shift;
	data->cur_x = data->st_x;
	data->cur_y = data->st_y;
	data->cur_c = data->st_c;
}

void	ft_end(t_data *data, int x, int y)
{
	data->end_x = x;
	data->end_y = y;
	data->end_z = data->z[y][x];
	data->end_c = ft_get_default_color(data->end_z, data);
	data->end_x *= data->zoom;
	data->end_y *= data->zoom;
	data->end_z *= data->zoom / data->z_corr;
	data->end_x -= (data->width * data->zoom) / 2;
	data->end_y -= (data->height * data->zoom) / 2;
	ft_rot_x(&data->end_y, &data->end_z, data->alpha);
	ft_rot_y(&data->end_x, &data->end_z, data->beta);
	ft_rot_z(&data->end_x, &data->end_y, data->gamma, data);
	if (data->projection == 0)
		ft_isometric(data);
	data->end_x += WIDTH / 2 + data->x_shift;
	data->end_y += (HEIGHT + data->height * data->zoom) / 2 + data->y_shift;
}
