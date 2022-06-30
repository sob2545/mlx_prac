/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_isometric.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:20:07 by sesim             #+#    #+#             */
/*   Updated: 2022/06/30 12:44:09 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include <stdlib.h>
#include <math.h>

static void	quaternion(double *x, double *y, double *z, double w, double angle)
{
	double	prev_x;
	double	prev_y;
	double	prev_z;

	prev_x = *x * sin(angle * (M_PI / 180));
	prev_y = *y * sin(angle * (M_PI / 180));
	prev_z = *z * sin(angle * (M_PI / 180));
	w = cos(angle * (M_PI / 180));
	*x = (1 - (2 * pow(prev_y, 2) - 2 * pow(prev_x, 2))) + ((2 * prev_x * prev_y) + (2 * w * prev_z)) + ((2 * prev_x * prev_z) - (2 * w * prev_y));
	*y = ((2 * prev_x - prev_y) + (2 * w * prev_z)) - (1 - (2 * pow(prev_x, 2)) - (2 * pow(prev_z, 2))) + ((2 * prev_y * prev_z) + (2 * w * prev_x));
	*z = ((2 * prev_x * prev_z) + (2 * w * prev_y)) + ((2 * prev_y * prev_z) - (2 * w * prev_x)) + (1 - (2 * pow(prev_x, 2)) - (2 * pow(prev_y, 2)));
}

static void	isometric(double *x, double *y, double z)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(M_PI / 6);
	*y = (prev_x + prev_y) * cos(M_PI / 3) - z;
}

void	vector_pixel(double x, double y, double z, void *mlx, void *win)
{
	isometric(&x, &y, z);
	mlx_pixel_put(mlx, win, x + (1980 / 2), y + (1080 / 2), 0xFFFFFF);
}

void	rotation_pixel(double x, double y, double z, void *mlx, void *win)
{
	quaternion(&x, &y, &z, 1, 180);
	isometric(&x, &y, z);
	mlx_pixel_put(mlx, win, x + (1980 / 2), y + (1080 / 2), 0xFFFFFF);
}

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1980, 1080, "test");

	vector_pixel(0, 0, 0, mlx, win);
	rotation_pixel(0, 0, 0, mlx, win);

	mlx_loop(mlx);
}
