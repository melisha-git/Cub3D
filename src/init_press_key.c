/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_press_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:57:13 by melisha           #+#    #+#             */
/*   Updated: 2021/01/27 22:34:25 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

enum Keys
{
    ESC = 0,
	W,
	S,
	A,
	D,
	UP,
	DOWN,
	LEFT,
	RIGHT
};

#ifdef __linux__
	int key_defines[] = {65307, 119, 115, 97, 100, 65362, 65364, 65363, 65361};
#endif
#ifdef __APPLE__
	int key_defines[] = {53, 126, 125, 0, 2, 13, 1, 124, 123};
#endif

int		but_hook(int /* keycode */)
{
	exit(0);
	return (1);
}

int		key_press(int keycode, t_vars *obj)
{
	if (keycode == key_defines[ESC])
	{
		mlx_destroy_window(obj->mlx, obj->win);
		exit(1);
	}
	if (keycode == key_defines[W] || keycode == key_defines[UP])
		obj->flag.up = 1;
	if (keycode == key_defines[S] || keycode == key_defines[DOWN])
		obj->flag.down = 1;
	if (keycode == key_defines[A])
		obj->flag.left = 1;
	if (keycode == key_defines[D])
		obj->flag.right = 1;
	if (keycode == key_defines[LEFT])
		obj->flag.turn_l = 1;
	if (keycode == key_defines[RIGHT])
		obj->flag.turn_r = 1;
	if (keycode == 48)
	{
		obj->player.life = obj->player.life - 10;
	}
	return (1);
}

int		key_release(int keycode, t_vars *obj)
{
	if (keycode == key_defines[W] || keycode == key_defines[UP])
		obj->flag.up = 0;
	if (keycode == key_defines[S] || keycode == key_defines[DOWN])
		obj->flag.down = 0;
	if (keycode == key_defines[A])
		obj->flag.left = 0;
	if (keycode == key_defines[D])
		obj->flag.right = 0;
	if (keycode == key_defines[LEFT])
		obj->flag.turn_l = 0;
	if (keycode == key_defines[RIGHT])
		obj->flag.turn_r = 0;
	return (1);
}

int		key_hook(t_vars *obj)
{
	if (obj->flag.up == 1)
		fn_move_up(obj);
	if (obj->flag.down == 1)
		fn_move_down(obj);
	if (obj->flag.turn_r == 1)
		fn_turn_r(obj);
	if (obj->flag.turn_l == 1)
		fn_turn_l(obj);
	if (obj->flag.right == 1)
		fn_move_right(obj);
	if (obj->flag.left == 1)
		fn_move_left(obj);
	mlx_destroy_image(obj->mlx, obj->img.img);
	obj->img.img = mlx_new_image(obj->mlx, obj->fill.r_one, obj->fill.r_two);
	obj->img.addr = mlx_get_data_addr(obj->img.img,
	&obj->img.bits_per_pixel, &obj->img.line_length, &obj->img.endian);
	if (!(fn_raycasting(obj)))
		fn_error("Error : unable to allocate memory \n");
	mlx_put_image_to_window(obj->mlx, obj->win, obj->img.img, 0, 0);
	fn_paint_life(obj);
	return (1);
}
