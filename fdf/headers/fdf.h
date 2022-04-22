/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:54:33 by chpark            #+#    #+#             */
/*   Updated: 2022/04/22 13:00:39 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

typedef struct t_data {
	size_t	width;
	size_t	height;
	int		**z;
	void	*mlx;
	void	*win;
	float	x0;
	float	x1;
	float	y0;
	float	y1;
	float	zoom;
	size_t	x;
	size_t	y;
	float	z0;
	int		color;
	float	move_x;
	float	move_y;
	float	move_z;
	int		projection;
	char	*addr;

}t_data;

void	xyz_init(t_data *info, char *file);
int		draw();
int		projection();
int		iso_projection();
int		fdf();

#endif
