/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_isometric.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:20:07 by sesim             #+#    #+#             */
/*   Updated: 2022/07/07 08:19:38 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static void	quaternion(double *x, double *y, double *z, double i, double j, double k, double angle)
{
	double	w;

	i *= sin(angle * (M_PI / 180));
	j *= sin(angle * (M_PI / 180));
	k *= sin(angle * (M_PI / 180));
	w = cos(angle * (M_PI / 180));
	*x = *x * (1 - (2 * pow(j, 2) - 2 * pow(k, 2))) + ((2 * i * j) + (2 * k * k)) + ((2 * i * k) - (2 * j * w));
	*y = *y * ((2 * i * j) + (2 * w * k)) - (1 - (2 * pow(i, 2)) - (2 * pow(k, 2))) + ((2 * j * k) + (2 * w * i));
	*z = *z * ((2 * i * k) + (2 * w * j)) + ((2 * j * k) - (2 * w * i)) + (1 - (2 * pow(i, 2)) - (2 * pow(j, 2)));
}

static void	isometric(double *x, double *y, double z)
{
	int	i;
	int	j;

	i = *x;
	j = *y;
	*x = (i - j) * cos(M_PI / 6);
	*y = (i + j) * cos(M_PI / 3) - z;
}
/*
void	vector_pixel(double x, double y, double z, void *mlx, void *win)
{
	isometric(&x, &y, z);
	mlx_pixel_put(mlx, win, x + (1980 / 2), y + (1080 / 2), 0xFFFFFF);
}
*/
void	rotation_pixel(double x, double y, double z, void *mlx, void *win)
{
	double	i;
	double	j;
	double	k;

	i = 1;
	j = 0;
	k = 0;
	quaternion(&x, &y, &z, i, j, k, 90);
	printf("%f, %f, %f\n", x, y, z);
	isometric(&x, &y, z);
	mlx_pixel_put(mlx, win, x + (1980 / 2), y + (1080 / 2), 0xFFFFFF);
}

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1980, 1080, "test");

	//vector_pixel(2, 4, 5, mlx, win);
	rotation_pixel(2, 4, 5, mlx, win);

	mlx_loop(mlx);
}
