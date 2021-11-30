/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <dasanter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 09:05:57 by dasanter          #+#    #+#             */
/*   Updated: 2021/11/30 14:03:14 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractole.h"
#include "mlx.h"

double	pix_calc(t_env *env, int p, char is)
{
	double	res;
	double	z;

	if (is == 'y')
		res = ((2 * ((p + 0.5) / env->size_y)) - 1) * env->mlx_img->zoom
			+ env->mlx_img->start_y;
	else
		res = ((3.5 * ((p + 0.5) / env->size_x)) - 2) * env->mlx_img->zoom
			+ env->mlx_img->start_x;
	if ((env->size_x / env->size_y) < 1)
	{
		z = env->size_y / env->size_x;
		if (is == 'y')
			return (z * res);
	}
	else
	{
		z = env->size_x / env->size_y;
		if (is == 'x')
			return (z * res);
	}
	return (res);
}

int	fract(double cx, double cy, t_env *env)
{
	if (env->set == 1)
		return (hsv_to_rgb(mandelbrot(get_complex(cx, cy),
					get_complex(cx, cy), env, env->iterations)));
	else if (env->set == 2)
		return (hsv_to_rgb(julia(get_complex(cx, cy), get_complex(0, 0),
					env, env->iterations)));
	else
		return (hsv_to_rgb(burn(get_complex(cx, cy), get_complex(0, 0),
					env, env->iterations)));
}

void	print_fract(t_env *env)
{
	double	cx;
	double	cy;
	int		ix;
	int		iy;
	int		i;

	iy = -1;
	while (++iy < env->size_y)
	{
		ix = -1;
		cy = pix_calc(env, iy, 'y');
		while (++ix < env->size_x)
		{
			cx = pix_calc(env, ix, 'x');
			px(env, ix, iy, fract(cx, cy, env));
		}
	}
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win,
		env->mlx_img->img_ptr, 0, 0);
}

int	mouse_hook(int button, int x, int y, t_env *env)
{
	if (button == BUTTON4)
	{
		env->mlx_img->start_x = pix_calc(env, x, 'x');
		env->mlx_img->start_y = pix_calc(env, y, 'y');
		env->mlx_img->zoom *= (0.9);
		env->mousex = x;
		env->mousey = y;
	}
	if (button == BUTTON5)
	{
		env->mlx_img->zoom *= 1.1;
		env->mousex = x;
		env->mousey = y;
	}
	print_fract(env);
	return (1);
}

int	keyboard_hook(int keycode, t_env *env)
{
	if (keycode == ESC_KEY)
		custom_exit(env, 0);
	if (keycode == PLUS_KEY || keycode == LEFT_KEY || keycode == RIGHT_KEY
		|| keycode == UP_KEY || keycode == DOWN_KEY || keycode == SP_KEY)
		move(keycode, env);
	if (keycode == ENTREE)
		env->h -= 20;
	if (keycode == TAB && env->is_julia == 1)
		env->is_julia = 0;
	else if (keycode == TAB && env->is_julia == 0)
		env->is_julia = 1;
	print_fract(env);
	return (1);
}
