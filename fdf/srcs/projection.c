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

static void	isometric(t_data *data)
{
	data->y1 = (data->x0 + data->y0) * sin(0.523599) - data->z0;
	data->x1 = (data->x0 - data->y0) * cos(0.523599);
}

static void	parallel(t_data *data)
{
	
	data->y1 = data->y0 - data->z0 * sin(0.785398);
	data->x1 = data->x0 - data->z0 * cos(0.785398);
}
