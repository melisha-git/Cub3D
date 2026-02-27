/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 21:27:12 by melisha           #+#    #+#             */
/*   Updated: 2021/01/27 20:33:19 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <math.h>
# include "get_next_line/get_next_line.h"
# include "cub_struct.h"
#ifdef __linux__
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
#endif
#ifdef __APPLE__
# include "../minilibx_mms/mlx.h"
#endif

char			*ft_itoa(int n);
char			**ft_split(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*fn_parser(t_vars *obj);
int				pars_r(char *line, t_vars *obj, int i);
int				ft_space(char *line, int i);
void			my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
char			*fn_init_vars_and_img_data_structs(t_vars *obj,
				t_img_data *img, int argc);
char			*fn_raycasting(t_vars *obj);
int				key_hook(t_vars *obj);
int				key_release(int keycode, t_vars *obj);
int				key_press(int keycode, t_vars *obj);
int				fn_hex_color(int r, int g, int b);
int				fn_card_point(t_vars *obj);
void			fn_raycast_init_before(t_vars *obj, int x);
void			fn_raycast_init_dir_r(t_vars *obj);
void			fn_raycast_init_hit(t_vars *obj);
int				fn_research_n(t_vars *obj);
char			*fn_init_texture(t_vars *obj);
int				but_hook(int keycode);
char			*fn_init_sprites(t_vars *obj);
unsigned int	texpixcolor(t_img_data *img, int x, int y);
void			fn_paint_sprites(t_vars *obj);
char			*fn_count_sprites(t_vars *obj);
void			fn_sort_sprites(t_vars *obj);
int				*fn_mas_rev(int *arr, t_vars *obj);
char			*fn_sprite_distance(t_vars *obj);
void			fn_raycast_init_after(t_vars *obj);
void			fn_shadow(int *color, double distance, float shaider);
void			fn_save(t_vars *obj);
void			fn_init_texpos(t_vars *obj);
int				fn_error(char *line);
int				pars_f(char *line, t_vars *obj, int i);
int				pars_c(char *line, t_vars *obj, int i);
int				pars_no(char *line, t_vars *obj, int i);
int				pars_so(char *line, t_vars *obj, int i);
int				pars_we(char *line, t_vars *obj, int i);
int				pars_ea(char *line, t_vars *obj, int i);
int				pars_s(char *line, t_vars *obj, int i);
char			*fn_pars_map(t_vars *obj, int fd);
char			*fn_pars_argument(t_vars *obj, int fd);
void			init_pos_sprite(t_vars *obj, int i);
void			fn_paint_sprite(t_vars *obj, int i);
int				fn_init_color(int *param, int *i, char *line, int f);
void			fn_paint_background(t_vars *obj);
char			*add_line(t_vars *obj, char *line);
char			*fn_add_plus(t_vars *obj);
char			*fn_search_no_wall(int i, int j, t_vars *obj);
char			*fn_check_pos(t_vars *obj, int j, size_t i);
char			*fn_init_no(t_vars *obj);
char			*fn_init_so(t_vars *obj);
char			*fn_init_we(t_vars *obj);
char			*fn_init_ea(t_vars *obj);
void			fn_move_up(t_vars *obj);
void			fn_move_down(t_vars *obj);
void			fn_move_right(t_vars *obj);
void			fn_move_left(t_vars *obj);
void			fn_turn_r(t_vars *obj);
void			fn_turn_l(t_vars *obj);
void			fn_paint_life(t_vars *obj);
#endif
