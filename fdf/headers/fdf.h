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

# define WIDTH				1280
# define HEIGHT				720
# define MX_INT 			2147483647
# define MN_INT 			-2147483648
# define ZOOM 				15
# define BACKGROUND					0x222222
# define COLOR_UP			0xEF8633
# define COLOR_RED					0xCC3333
# define COLOR_ZERO			0x33FF00
# define COLOR_WHITE		0xFFFFCC
# define COLOR_DEEP			0x00CCFF
# define ISO_ANGLE 			0.523599
# define PAR_ANGLE 			0.785398

typedef struct s_data
{
	int				width;
	int				height;
	int				**z;
	int				maxz;
	int				minz;
	void					*mlx;
	void					*win;
	void					*img;
	int				line_point;
	int				zoom;
	int				projection;
	int				st_x;
	int				st_y;
	int				st_z;
	unsigned int	st_c;
	int				end_x;
	int				end_y;
	int				end_z;
	unsigned int	end_c;
	int				cur_x;
	int				cur_y;
	unsigned int	cur_c;
	unsigned int	color;
	int				z_corr;
	double			alpha;
	double			beta;
	double			gamma;
	size_t			x;
	size_t			y;
	int				x_shift;
	int				y_shift;
	char			*addr;
	int				bit_per_pixel;
	int				size_line;
	int				endian;
}				t_data;

// map_read.c
void			xyz_init(t_data *info, char *file);
// fdf.c
int				main(int ac, char **av);
// st_end.c
void			ft_st(t_data *data, int x, int y);
void			ft_end(t_data *data, int x, int y);
// draw.c
void			draw_image(t_data *data, int x, int y);
// draw_utils.c
unsigned int	ft_get_default_color(int z, t_data *data);
unsigned int	ft_get_color(t_data *data, int x, int y);
void			MAX_MIN_data(t_data *data);
// projection.c
void			ft_isometric(t_data *data);
void			ft_parallel(t_data *data);
void			ft_key3(int key, t_data *data);
int				ft_abs(int a);
int				ft_comper(int a, int b);
#endif
