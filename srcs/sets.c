/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <dasanter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 09:03:05 by dasanter          #+#    #+#             */
/*   Updated: 2021/11/29 09:10:36 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractole.h"

t_hsv mandelbrot(t_complex z, t_complex c, data_str *env, int iteration_max)
{
	int i;
	t_hsv color;
	i = 0;

	for (i = 0; i < iteration_max && get_complex_size(z) < 4; i++)
	{
		z = add_comp(square_comp(z), c);
	}

	if (i == iteration_max)
	{
		color.h = 0;
		color.s = 0;
		color.v = 0;
		return (color);
	}
	color.h = env->h - i;
	color.s = i*3;                
	color.v = 100  - ((i * 3) % 100);
	return (color);
}

t_hsv julia(t_complex z, t_complex c, data_str *env, int iteration_max)
{
	int i;
	t_hsv color;
	i = 0;

	for (i = 0; i < iteration_max && get_complex_size(z) < 4; i++)
	{
		z = add_comp(square_comp(z), get_complex(env->j_r, env->j_i));
	}

	if (i == iteration_max)
	{
		color.h = 0;
		color.s = 0;
		color.v = 0;
		return (color);
	}
	color.h = env->h;
	color.s = i;                
	color.v = 100;
	return (color);
}

t_hsv burn(t_complex c, t_complex z, data_str *env, int iteration_max)
{
	int i;
	double tmp;
	t_hsv color;
	i = 0;

	for (i = 0; i < iteration_max && get_complex_size(z) < 4; i++)
	{
		tmp = (z.r * z.r) - (z.i * z.i) + c.r;
		z.i = (2 * fabs(z.r) * fabs(z.i)) + c.i;
		z.r = tmp;
	}

	if (i == iteration_max)
	{
		color.h = 0;
		color.s = 0;
		color.v = 0;
		return (color);
	}
	color.h = env->h;
	color.s = i;                
	color.v = env->v;
	return (color);
}
