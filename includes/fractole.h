/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractole.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <dasanter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:27:12 by dasanter          #+#    #+#             */
/*   Updated: 2021/11/29 11:46:07 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> 
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>

typedef struct s_img
{
	void			*img_ptr;
	char			*data;
	int				size_l;
	int				bpp;
	int				endian;
	double			start_x;
	double			start_y;
	double			zoom;

}				t_img;

typedef struct s_list
{
	int				size_x;
	int				size_y;
	int				is_julia;
	double			j_r;
	double			j_i;
	void			*mlx_ptr;
	void			*mlx_win;
	char			*test_text;
	int				mousex;
	int				mousey;
	int				set;
	double			cxmin;
	double			cymin;
	double			cxmax;
	double			h;
	double			v;
	double			cymax;
	int				iterations;
	t_img			*mlx_img;
}			t_env;

typedef struct s_complex
{
	double			r;
	double			i;
}					t_complex;

typedef struct s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct s_hsv
{
	double			h;
	double			s;
	double			v;
}					t_hsv;

int			hsv_to_rgb(t_hsv hsv);
int			rgb_to_int(t_rgb rgb);
int			get_rgb(unsigned char r, unsigned char g, unsigned char b);
void		px(t_env *t_envc, int x, int y, int c);
t_complex	add_comp(t_complex a, t_complex b);
t_complex	square_comp(t_complex a);
t_complex	get_complex(double x, double y);
double		get_complex_size(t_complex a);
void		custom_exit(t_env *env, int ret);
int			mouse_hook(int button, int x, int y, t_env *env);
int			keyboard_hook(int keycode, t_env *env);
void		print_fract(t_env *env);
t_hsv		mandelbrot(t_complex z, t_complex c, t_env *env, int iteration_max);
t_hsv		julia(t_complex z, t_complex c, t_env *env, int iteration_max);
t_hsv		burn(t_complex z, t_complex c, t_env *env, int iteration_max);
void		move(int keycode, t_env *env);
double		pix_calc(t_env *env, int p, char is);
int			norme(double c, double h, double x, double m);
int			get_rgb(unsigned char r, unsigned char g, unsigned char b);
