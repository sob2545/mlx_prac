/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   euler_isometric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:20:07 by sesim             #+#    #+#             */
/*   Updated: 2022/07/07 08:22:32 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static void	rotate_x(double *y, double *z, double angle)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(angle) + (*z) * sin(angle);
	*z = -prev_y * sin(angle) + (*z) * cos(angle);
}

/*
static void	rotate_y(int *x, int *z, double angle)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(angle) + (*z) * sin(angle);
	*z = -prev_x * sin(angle) + (*z) * cos(angle);
}

static void	rotate_z(int *x, int *y, double angle)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(angle) - prev_y * sin(angle);
	*y = prev_x * sin(angle) + prev_y * cos(angle);
}

static void	isometric(int *x, int *y, int z)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(M_PI / 6);
	*y = (prev_x + prev_y) * cos(M_PI / 3) - z;
}

void	vector_pixel(int x, int y, int z, void *mlx, void *win)
{
	isometric(&x, &y, z);
	mlx_pixel_put(mlx, win, x + (1980 / 2), y + (1080 / 2), 0xFFFFFF);
}
*/

void	euler_pixel(double x, double y, double z, void *mlx, void *win)
{
	//rotate_z(&x, &y, (45 * (M_PI / 180)));
	rotate_x(&y, &z, ((90) * (M_PI / 180)));
	printf("%f, %f, %f", x, y, z);
	mlx_pixel_put(mlx, win, x + (1980 / 2), y + (1080 / 2), 0xFFFFFF);
}

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1980, 1080, "test");

	/*
	vector_pixel(100, 0, 0, mlx, win);
	vector_pixel(0, -100, 0, mlx, win);
	vector_pixel(100, -100, 0, mlx, win);
	vector_pixel(100, 0, 100, mlx, win);
	vector_pixel(100, -100, 100, mlx, win);
	vector_pixel(0, 0, 100, mlx, win);
	vector_pixel(0, -100, 100, mlx, win);
	vector_pixel(0, 0, 0, mlx, win);
	*/

	euler_pixel(2, 4, 5, mlx, win);
	/*
	euler_pixel(0, -100, 0, mlx, win);
	euler_pixel(100, -100, 0, mlx, win);
	euler_pixel(100, 0, 100, mlx, win);
	euler_pixel(100, -100, 100, mlx, win);
	euler_pixel(0, 0, 100, mlx, win);
	euler_pixel(0, -100, 100, mlx, win);
	euler_pixel(0, 0, 0, mlx, win);
	*/
	mlx_loop(mlx);
}
