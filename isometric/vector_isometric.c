/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_isometric.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:20:07 by sesim             #+#    #+#             */
/*   Updated: 2022/06/27 10:49:23 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include <stdlib.h>
#include <math.h>

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

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1980, 1080, "test");

	vector_pixel(100, 0, 0, mlx, win);
	vector_pixel(0, -100, 0, mlx, win);
	vector_pixel(100, -100, 0, mlx, win);
	vector_pixel(100, 0, 100, mlx, win);
	vector_pixel(100, -100, 100, mlx, win);
	vector_pixel(0, 0, 100, mlx, win);
	vector_pixel(0, -100, 100, mlx, win);
	vector_pixel(0, 0, 0, mlx, win);

	mlx_loop(mlx);
}
