/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_iso.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:29:16 by tmerida-          #+#    #+#             */
/*   Updated: 2022/04/06 17:29:17 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	ft_isometric(t_data *data)
{
	int	temp_x;
	int	temp_y;

	temp_x = data->st_x;
	temp_y = data->st_y;
	data->st_y = (temp_x + temp_y) * sin(ISO_ANGLE) - data->st_z;
	data->st_x = (temp_x - temp_y) * cos(ISO_ANGLE);
}

void	ft_parallel(t_data *data)
{
	int	temp_x;
	int	temp_y;

	temp_x = data->st_x;
	temp_y = data->st_y;
	data->st_y = temp_y - data->st_z * sin(PAR_ANGLE);
	data->st_x = temp_x - data->st_z * cos(PAR_ANGLE);
}

void	ft_key3(int key, t_data *data)
{
	if (key == 34)//'i'
		data->projection = 0;
	else if (key == 5)//'g'
		data->gamma = data->gamma + (M_PI / 2);
	else if (key == 43)//'<'
		data->color += 100;
	else if (key == 47)//'>'
		data->color -= 100;
	return ;
}

int	ft_abs(int a)
{
	if (a < 0)
		a = -a;
	return (a);
}

int	ft_comper(int a, int b)
{
	if (a < b)
		return (1);
	return (-1);
}
