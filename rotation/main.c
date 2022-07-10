#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define TITLE "This is Quaternion"

#define KEY_Q 12
#define KEY_W 13
#define KEY_E 14
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

#include "../mlx/mlx.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>

void	*mlx_ptr;
void	*win_ptr;

typedef struct s_quaternion
{
	double	w;
	double	x;
	double	y;
	double	z;
	double	arrays[3][3];
}	t_quaternion;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

int		key_hook(int keycode, void *param);
void	rotate_q(t_quaternion *q, double w, double x, double y, double z);
int		loop_hook(void *param);
void	calc_quaternion(t_quaternion *q);
void	draw(t_quaternion q);
t_point	rotate(t_point from, t_quaternion q);
void	draw_vector(t_point p, int color);

int	main(void)
{
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
	t_quaternion	q;
	q.w = 1.0;
	q.x = q.y = q.z = 0.0;
	mlx_key_hook(win_ptr, &key_hook, &q);
	mlx_loop_hook(mlx_ptr, &loop_hook, &q);
	mlx_loop(mlx_ptr);
}

int	key_hook(int keycode, void *param)
{
	const double	cos15 = cos(M_PI / 24);
	const double	sin15 = sin(M_PI / 24);
	t_quaternion	*q = (t_quaternion *)param;

	if (keycode == KEY_Q)
		rotate_q(q, cos15, sin15, 0, 0);
	else if (keycode == KEY_E)
		rotate_q(q, cos15, -sin15, 0, 0);
	else if (keycode == KEY_S)
		rotate_q(q, cos15, 0, sin15, 0);
	else if (keycode == KEY_W)
		rotate_q(q, cos15, 0, -sin15, 0);
	else if (keycode == KEY_D)
		rotate_q(q, cos15, 0, 0, sin15);
	else if (keycode == KEY_A)
		rotate_q(q, cos15, 0, 0, -sin15);
	return (keycode);
}
void	rotate_q(t_quaternion *q, double w, double x, double y, double z)
{
	double	temp[4];

	temp[0] = q->w * w - q->x * x - q->y * y - q->z * z;
	temp[1] = q->x * w + q->w * x - q->z * y + q->y * z;
	temp[2] = q->y * w + q->z * x + q->w * y - q->x * z;
	temp[3] = q->z * w - q->y * x + q->x * y + q->w * z;
	q->w = temp[0];
	q->x = temp[1];
	q->y = temp[2];
	q->z = temp[3];
}

int	loop_hook(void *param)
{
	static t_quaternion	prev_q;
	t_quaternion		*q = (t_quaternion *)param;

	if (memcmp(q, &prev_q, sizeof(t_quaternion)))
	{
		prev_q = *q;
		calc_quaternion(q);
		draw(*q);
		return (1);
	}
	return (0);
}

void	calc_quaternion(t_quaternion *q)
{
	double	multies[4][4];

	multies[0][1] = q->w * q->x;
	multies[0][2] = q->w * q->y;
	multies[0][3] = q->w * q->z;
	multies[1][1] = q->x * q->x;
	multies[1][2] = q->x * q->y;
	multies[1][3] = q->x * q->z;
	multies[2][2] = q->y * q->y;
	multies[2][3] = q->y * q->z;
	multies[3][3] = q->z * q->z;
	q->arrays[0][0] = 1. - 2. * multies[2][2] - 2. * multies[3][3];
	q->arrays[0][1] = 2. * multies[1][2] - 2. * multies[0][3];
	q->arrays[0][2] = 2. * multies[1][3] + 2. * multies[0][2];
	q->arrays[1][0] = 2. * multies[1][2] + 2. * multies[0][3];
	q->arrays[1][1] = 1. - 2. * multies[1][1] - 2. * multies[3][3];
	q->arrays[1][2] = 2. * multies[2][3] - 2. * multies[0][1];
	q->arrays[2][0] = 2. * multies[1][3] - 2. * multies[0][2];
	q->arrays[2][1] = 2. * multies[2][3] + 2. * multies[0][1];
	q->arrays[2][2] = 1. - 2. * multies[1][1] - 2. * multies[2][2];
}

void	draw(t_quaternion q)
{
	t_point	x_axis, y_axis, z_axis;

	mlx_clear_window(mlx_ptr, win_ptr);
	x_axis.x = 200.0;
	x_axis.y = x_axis.z = 0.0;
	y_axis.y = 200.0;
	y_axis.x = y_axis.z = 0.0;
	z_axis.z = 200.0;
	z_axis.x = z_axis.y = 0.0;
	draw_vector(rotate(x_axis, q), 0xFF0000);
	draw_vector(rotate(y_axis, q), 0x00FF00);
	draw_vector(rotate(z_axis, q), 0x0000FF);
}

t_point	rotate(t_point from, t_quaternion q)
{
	t_point	to;

	to.x = from.x * q.arrays[0][0] + from.y * q.arrays[0][1]
		+ from.z * q.arrays[0][2];
	to.y = from.x * q.arrays[1][0] + from.y * q.arrays[1][1]
		+ from.z * q.arrays[1][2];
	to.z = from.x * q.arrays[2][0] + from.y * q.arrays[2][1]
		+ from.z * q.arrays[2][2];
	return (to);
}



void	draw_vector(t_point p, int color)
{
	double	dt = fmax(fabs(p.y), fabs(p.z));
	double	dx = p.y / dt, dy = p.z / dt;
	double	x = (double)SCREEN_WIDTH / 2, y = (double)SCREEN_HEIGHT / 2;
	for (double i=0; i<=dt; i+=1.0)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, (int)x, (int)y, color);
		x += dx;
		y -= dy;
	}
}
