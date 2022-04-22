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

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (0);
	ft_init_data(&data);
	ft_read_map(&data, av[1]);
	if (data.erfl)
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
