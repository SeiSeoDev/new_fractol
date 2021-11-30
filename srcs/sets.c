/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <dasanter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 09:03:05 by dasanter          #+#    #+#             */
/*   Updated: 2021/11/30 16:11:37 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractole.h"

void	clean(t_hsv	*color, int i)
{
	color->h = 240;
	color->s = i;
	color->v = 80;
}

t_hsv	mandelbrot(t_complex z, t_complex c, t_env *env, int iteration_max)
{
	int		i;
	t_hsv	color;

	i = -1;
	while (++i < iteration_max && get_complex_size(z) < 4)
		z = add_comp(square_comp(z), c);
	if (i == iteration_max)
	{
		color.h = 0;
		color.s = 0;
		color.v = 0;
		return (color);
	}
	color.h = env->h;
	color.s = env->h + i * 3;
	color.v = env->h + 100 - ((i * 3) % 100);
	if (env->clean && i != iteration_max)
		clean(&color, i);
	return (color);
}

t_hsv	julia(t_complex z, t_complex c, t_env *env, int iteration_max)
{
	int		i;
	t_hsv	color;

	i = -1;
	while (++i < iteration_max && get_complex_size(z) < 4)
		z = add_comp(square_comp(z), get_complex(env->j_r, env->j_i));
	if (i == iteration_max)
	{
		color.h = 0;
		color.s = 0;
		color.v = 0;
		return (color);
	}
	color.h = env->h;
	color.s = env->h + i;
	color.v = env->h + 100 - ((i * 3) % 100);
	if (env->clean && i != iteration_max)
		clean(&color, i);
	return (color);
}

t_hsv	burn(t_complex c, t_complex z, t_env *env, int iteration_max)
{
	int		i;
	double	tmp;
	t_hsv	color;

	i = -1;
	while (++i < iteration_max && get_complex_size(z) < 4)
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
	color.s = env->h + i;
	color.v = env->h + 100 - ((i * 3) % 100);
	if (env->clean && i != iteration_max)
		clean(&color, i);
	return (color);
}
