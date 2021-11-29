/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <dasanter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 09:05:57 by dasanter          #+#    #+#             */
/*   Updated: 2021/11/29 09:11:07 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractole.h"
#include "mlx.h"
double pix_calc(data_str *env, int p, char is)
{
	double res;
	double z;

	if (is == 'y')
		res = ((2 * ((p + 0.5) / env->size_y)) - 1) * env->mlx_img->ZOOM + env->mlx_img->START_Y;
	else
		res = ((3.5 * ((p + 0.5) / env->size_x)) - 2) * env->mlx_img->ZOOM + env->mlx_img->START_X;
	if ((env->size_x / env->size_y) < 1)
	{
		z = env->size_y / env->size_x;
		if (is == 'y')
			return (z * res);
		else
			return (res);
	}
	else
	{
		z = env->size_x / env->size_y;
		if (is == 'x')
			return (z * res);
		else
			return (res);
	}
	return (res); 
}

void print_fract(data_str *env)
{

		double Cx,Cy;
		int iX,iY;
		int i;

		for( iY = 0;iY<env->size_y;iY++)
		{
			Cy = pix_calc(env, iY, 'y');
			 for(iX=0;iX<env->size_x;iX++)
			 {       
				 Cx = pix_calc(env, iX, 'x');
				if (env->set == 1)
					px_to_onscreenimg(env, iX, iY, hsv_to_rgb(mandelbrot(get_complex(Cx, Cy), get_complex(Cx, Cy), env, env->iterations)));
				else if (env->set == 2)
					px_to_onscreenimg(env, iX, iY, hsv_to_rgb(julia(get_complex(Cx, Cy), get_complex(0, 0), env, env->iterations)));
				else
					px_to_onscreenimg(env, iX, iY, hsv_to_rgb(burn(get_complex(Cx, Cy), get_complex(0, 0), env, env->iterations)));
			}
		}
		mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img->img_ptr, 0, 0);
}

int mouse_hook(int button,int x,int y,data_str *env){
	if (button == 4)
		{
		env->mlx_img->START_X = pix_calc(env, x, 'x');
		env->mlx_img->START_Y = pix_calc(env, y, 'y');
		env->mlx_img->ZOOM *= (0.9);
		env->mousex = x;
		env->mousey = y;
		}
	if (button == 5)
	{
		env->mlx_img->ZOOM *= 1.1;
		env->mousex = x;
		env->mousey = y;
	}
	print_fract(env);
	return (1);
}

int keyboard_hook(int keycode,data_str *env)
{
	double h;
	double w;
	
	h = (pix_calc(env, env->size_y, 'y') - pix_calc(env, 0, 'y')) * env->mlx_img->ZOOM;
	w = (pix_calc(env, env->size_x, 'x') - pix_calc(env, 0, 'x')) * env->mlx_img->ZOOM;  
	if (keycode == 65307)
		custom_exit(env, 0);
	if (keycode == 65451)
		env->mlx_img->ZOOM *= 0.9;
	if (keycode == 65361)
		env->mlx_img->START_X -= w * 0.1;
	if (keycode == 65363)
		env->mlx_img->START_X += w * 0.1;
	if (keycode == 65362)
		env->mlx_img->START_Y -= h * 0.1;
	if (keycode == 65364)
		env->mlx_img->START_Y += h * 0.1;
	if (keycode == 32)
	{
		if (env->set < 3)
			env->set += 1;
		else
			env->set = 1;
	}
	if (keycode == 65293)
		env->h -= 20;
	if (keycode == 65289 && env->is_julia == 1)
			env->is_julia = 0;
	else if (keycode == 65289 && env->is_julia == 0)
			env->is_julia = 1;
	print_fract(env);
	return 1;
}
