/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 21:33:19 by melisha           #+#    #+#             */
/*   Updated: 2021/01/27 20:29:28 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_STRUCT_H
# define CUB_STRUCT_H

typedef struct	s_param
{
	int		r;
	int		no;
	int		so;
	int		we;
	int		ea;
	int		s;
	int		f;
	int		c;
	int		p;
}				t_param;
typedef	struct	s_filliing
{
	int		r_one;
	int		r_two;
	int		f_r;
	int		f_g;
	int		f_b;
	int		c_r;
	int		c_g;
	int		c_b;
	char	*no;
	char	*so;
	char	*we;
	char	*s;
	char	*ea;
	char	**map;
	char	*buff;
	char	*file;
	int		width_map;
	int		height_map;
	t_param	flag_params;
}				t_filling;
typedef struct	s_img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img_data;
typedef struct	s_sprite
{
	int			s_h;
	int			s_w;
	int			start_x;
	int			start_y;
	int			end_x;
	int			end_y;
	double		pos_x;
	double		pos_y;
	double		inv_deg;
	double		transform_x;
	double		transform_y;
	int			sprite_screen;
	int			move_screen;
	int			t_width;
	int			t_height;
	int			tex_x;
	int			tex_y;
	int			*sprite_x;
	int			*sprite_y;
	float		*distance;
	int			len;
	t_img_data	img_sprites;
}				t_sprite;
typedef struct	s_texture
{
	int			t_width;
	int			t_height;
	int			tex_x;
	int			tex_y;
	double		wall;
	double		step;
	double		texpos;
	t_img_data	img_text_no;
	t_img_data	img_text_so;
	t_img_data	img_text_we;
	t_img_data	img_text_ea;
	t_sprite	sprite;
}				t_texture;
typedef	struct	s_player
{
	float	pos_x;
	float	pos_y;
	float	speed;
	float	angle;
	int		max_draw;
	float	dir_x;
	float	dir_y;
	char	card_point;
	int		life;
	double	scale_shadow;
}				t_player;
typedef struct	s_raycast
{
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		map_x;
	int		map_y;
	double	perp_wall_dist;
	double	*perpbuffer;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		lineh;
	int		start;
	int		end;
}				t_raycast;
typedef struct	s_ray
{
	float		pos_x;
	float		pos_y;
	double		plane_x;
	double		plane_y;
	double		speed;
	double		dir_x;
	double		dir_y;
	t_raycast	raycast;
}				t_ray;
typedef struct	s_flags
{
	int up;
	int down;
	int right;
	int left;
	int turn_l;
	int turn_r;
}				t_flags;
typedef struct	s_screen
{
	int height;
	int	width;
}				t_screen;
typedef struct	s_vars
{
	void		*mlx;
	void		*win;
	t_flags		flag;
	t_filling	fill;
	t_img_data	img;
	t_player	player;
	t_ray		ray;
	t_texture	texture;
	t_screen	screen;
}				t_vars;
#endif
