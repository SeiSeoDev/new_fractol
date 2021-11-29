/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <dasanter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 09:02:05 by dasanter          #+#    #+#             */
/*   Updated: 2021/11/29 11:41:19 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractole.h"

t_complex	add_comp(t_complex a, t_complex b)
{
	t_complex	result;

	result.r = a.r + b.r;
	result.i = a.i + b.i;
	return (result);
}

t_complex	square_comp(t_complex a)
{
	t_complex	result;
	double		tmp;

	tmp = a.r;
	result.r = a.r * a.r - a.i * a.i;
	result.i = 2 * tmp * a.i;
	return (result);
}

t_complex	get_complex(double x, double y)
{
	t_complex	result;

	result.r = x;
	result.i = y;
	return (result);
}

double	get_complex_size(t_complex a)
{
	return (fabs(a.r * a.r) + fabs(a.i * a.i));
}

void	move(int keycode, t_env *env)
{
	double	h;
	double	w;

	h = (pix_calc(env, env->size_y, 'y') - pix_calc(env, 0, 'y'))
		* env->mlx_img->zoom;
	w = (pix_calc(env, env->size_x, 'x') - pix_calc(env, 0, 'x'))
		* env->mlx_img->zoom;
	if (keycode == 65451)
		env->mlx_img->zoom *= 0.9;
	if (keycode == 65361)
		env->mlx_img->start_x -= w * 0.1;
	if (keycode == 65363)
		env->mlx_img->start_x += w * 0.1;
	if (keycode == 65362)
		env->mlx_img->start_y -= h * 0.1;
	if (keycode == 65364)
		env->mlx_img->start_y += h * 0.1;
	if (keycode == 32)
	{
		if (env->set < 3)
			env->set += 1;
		else
			env->set = 1;
	}
}
