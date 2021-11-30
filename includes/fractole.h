/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractole.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <dasanter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:27:12 by dasanter          #+#    #+#             */
/*   Updated: 2021/11/30 16:10:26 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOLE_H
# define FRACTOLE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> 
# include <sys/stat.h>
# include <fcntl.h>
# include <time.h>
# include <math.h>

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
	int				clean;
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
# ifdef LINUX
#  define BUTTON1				1
#  define BUTTON2				2
#  define BUTTON3				3
#  define BUTTON4				4
#  define BUTTON5				5
#  define KEYPRESS				2
#  define KEYRELEASE			3
#  define BUTTONPRESS			4
#  define BUTTONRELEASE			5
#  define MOTIONNOTIFY			6
#  define ENTERNOTIFY			7
#  define LEAVENOTIFY			8
#  define DESTROYNOTIFY			17
#  define SP_KEY 				32
#  define ESC_KEY 				65307
#  define LEFT_KEY				65361
#  define UP_KEY				65362
#  define RIGHT_KEY				65363
#  define DOWN_KEY				65364
#  define MULTI_KEY				65450
#  define P_BUT					35
#  define TAB					48
#  define ENTREE				76
#  define PLUS_KEY				65451
#  define MOINS_KEY				65453
#  define DIV_KEY				65455
# else
#  define BUTTON1				1
#  define BUTTON2				2
#  define BUTTON3				3
#  define BUTTON4				4
#  define P_BUT					35
#  define BUTTON5				5
#  define KEYPRESS				2
#  define KEYRELEASE			3
#  define BUTTONPRESS			4
#  define BUTTONRELEASE			5
#  define MOTIONNOTIFY			6
#  define ENTERNOTIFY			7
#  define LEAVENOTIFY			8
#  define DESTROYNOTIFY			17
#  define ESC_KEY 				53
#  define SP_KEY 				49
#  define TAB					48
#  define ENTREE				36
#  define LEFT_KEY				123
#  define UP_KEY				126
#  define RIGHT_KEY				124
#  define DOWN_KEY				125
#  define MULTI_KEY				67
#  define PLUS_KEY				69
#  define MOINS_KEY				78
#  define DIV_KEY				75
# endif
#endif