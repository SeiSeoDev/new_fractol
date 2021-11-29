/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <dasanter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 09:01:41 by dasanter          #+#    #+#             */
/*   Updated: 2021/11/29 09:06:24 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractole.h"
#include "../mlx/mlx.h"

void    custom_exit(data_str *env, int ret)
{
 //       mlx_destroy_image(env->mlx_ptr, env->mlx_img);
 	printf("1\n");
	mlx_destroy_window(env->mlx_ptr, env->mlx_win);
	if (env)
	{
		if (env->mlx_img)
		{
			mlx_destroy_image(env->mlx_ptr, env->mlx_img->img_ptr);
			free(env->mlx_img);
		}
		free(env);
	}
	exit(ret);
}

void set_set(char **set, data_str *env)
{
	char c;

	if(set[1])
	{
		c = set[1][0];
		if (c == 'm')
			env->set = 1;
		else if (c == 'j')
			env->set = 2;
		else if (c == 'b')
			env->set = 3;
	}
	else
	{
		printf("USAGE : ./fract-ol m (mandelbroth)\n./fract-ol j (julia)\n./fract-ol b (burning-ship)\n");
		free(env->mlx_img);
		free(env);
		exit(EXIT_FAILURE);
	}
}

int mouse(int x, int y, data_str *env)
{
	if (env->is_julia == 1)
	{
		env->j_r = ((double)x * (1.5 + 1.5)/env->size_x) -1.5;
		env->j_i = ((double)y * (1.5 + 1.5)/env->size_y) -1.5;
	}
	return (1);
}

void	init(data_str *env)
{
	env->j_r = -0.8;
	env->j_i = 0.2;
	env->is_julia = 0;
	env->size_x = 1280;
	env->size_y = 720;
	env->mlx_img->START_X = 0;
	env->mlx_img->START_Y = 0.0;
	env->mlx_img->ZOOM = 0.99;
	env->mousex = 0;
	env->mousey = 0;
	env->iterations = 100;
	env->h = 240;
	env->v = 100;
}

int main(int ac, char **av)
{
	data_str *env;

	if (!(env = malloc(sizeof(data_str))))
		return (0);
	if (!(env->mlx_img = malloc(sizeof(t_img))))
		return (0);
	set_set(av, env);
	init(env);
	env->mlx_ptr = mlx_init();
	env->mlx_win = mlx_new_window(env->mlx_ptr, env->size_x, env->size_y, "new Window");
	env->mlx_img->img_ptr = mlx_new_image(env->mlx_ptr , env->size_x, env->size_y);
	env->mlx_img->data = (char *)mlx_get_data_addr(env->mlx_img->img_ptr, &env->mlx_img->bpp, &env->mlx_img->size_l,
		&env->mlx_img->endian);
	printf("bpp %d, size %d\n", env->mlx_img->bpp, env->mlx_img->size_l);
	print_fract(env);
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img->img_ptr, 0, 0);
	mlx_mouse_hook(env->mlx_win, mouse_hook, env);
	mlx_key_hook(env->mlx_win, keyboard_hook, env);
	mlx_hook(env->mlx_win, 6, 1L<<6, mouse, env);
	mlx_loop(env->mlx_ptr);
	return (1);
}
