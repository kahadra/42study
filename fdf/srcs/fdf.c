/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:25:53 by chpark            #+#    #+#             */
/*   Updated: 2022/04/22 16:26:25 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

static void	ft_init_data(t_data *data)
{
	data->height = 0;
	data->width = 0;
	data->zoom = ZOOM;
	data->projection = 0;
	data->mlx = NULL;
	data->win = NULL;
	data->x_shift = 0;
	data->y_shift = 0;
	data->z_corr = 2;
	data->maxz = MN_INT;
	data->minz = MX_INT;
}

static void	ft_clear_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		if (data->z[i])
		{
			free (data->z[i]);
			data->z[i] = NULL;
		}
		i++;
	}
	free (data->z);
	data->z = NULL;
}

static void	ft_key2(int key, t_data *data)
{
	if (key == 78)//'-'
		data->zoom -= 1;
	else if (key == 69)//'+'
		data->zoom += 1;
	else if (key == 91)//10key '8'
		data->alpha += 0.05;
	else if (key == 84)//10key '2' 
		data->alpha -= 0.05;
	else
		ft_key3(key, data);
	return ;
}

static int	ft_key(int key, t_data *data)
{
	if (key == 53)//'esc'
		exit (0);
	else if (key == 89)//10key '7'
		data->beta += 0.05;
	else if (key == 92)//10key '9'
		data->beta -= 0.05;
	else if (key == 86)//10key '4'
		data->gamma += 0.05;
	else if (key == 88)//10key '6'
		data->gamma -= 0.05;
	else if (key == 35)//'p'
	{
		data->projection = 1;
		data->gamma = 0;
		data->beta = 0;
		data->alpha = 0;
	}
	else if (key == 0)//'a'
		data->alpha = data->alpha + (M_PI / 2);
	else if (key == 11)//'b'
		data->beta = data->beta + (M_PI / 2);
	else
		ft_key2(key, data);
	draw_image(data, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (0);
	ft_init_data(&data);
	xyz_init(&data, av[1]);
	MAX_MIN_data(&data);
	if (!data.z)
	{
		ft_clear_data(&data);
		return (0);
	}
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "FdF");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &(data.bit_per_pixel),
			&(data.size_line), &(data.endian));
	draw_image(&data, 0, 0);
	mlx_hook(data.win, 2, 0, ft_key, &data);
	mlx_loop(data.mlx);
	ft_clear_data(&data);
	return (0);
}
