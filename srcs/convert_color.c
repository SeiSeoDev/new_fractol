/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <dasanter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 09:01:53 by dasanter          #+#    #+#             */
/*   Updated: 2021/11/29 11:41:19 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractole.h"

int	get_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	int			result;

	result = r;
	result = (result << 8) + g;
	result = (result << 8) + b;
	return (result);
}

int	rgb_to_int(t_rgb rgb)
{
	return (get_rgb(rgb.r, rgb.g, rgb.b));
}

t_rgb	int_to_rgb(int c)
{
	t_rgb		rgb;

	rgb.r = c >> 16;
	rgb.g = (c >> 8) - ((c >> 16) * 0x100);
	rgb.b = c - ((c >> 8) * 0x100);
	return (rgb);
}

int	hsv_to_rgb(t_hsv hsv)
{
	double	c;
	double	h;
	double	x;
	double	m;

	c = (double)hsv.v / 100 * ((double)hsv.s / 100);
	h = (double)hsv.h / 60;
	x = c * (1 - fabsf((float)(h - (h / 2 * 2) - 1)));
	m = (double)hsv.v / 100 - c;
	return (norme(c, h, x, m));
}

void	px(t_env *t_envc, int x, int y, int c)
{
	t_envc->mlx_img->data[x * 4 + y * t_envc->size_x * 4]
		= int_to_rgb(c).b;
	t_envc->mlx_img->data[x * 4 + y * t_envc->size_x * 4 + 1]
		= int_to_rgb(c).g;
	t_envc->mlx_img->data[x * 4 + y * t_envc->size_x * 4 + 2]
		= int_to_rgb(c).r;
	t_envc->mlx_img->data[x * 4 + y * t_envc->size_x * 4 + 3]
		= 0;
}
