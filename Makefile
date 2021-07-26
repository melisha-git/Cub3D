NAME = cub3D

CC = gcc -Wall -Wextra -Werror

MLX = minilibx_mms/

HEAD = cub.h cub_struct.h get_next_line/get_next_line.h

SRC = error.c fn_init_raycast.c \
		fn_save.c init_param.c \
		init_pos_sprite.c init_press_key.c \
		init_texture_card_p.c main.c move.c \
		my_mlx.c paint_background.c paint_sprite.c \
		raycasting.c research.c shadow.c sprites.c \
		turn.c work_of_color.c parser/init_color.c \
		parser/no_leaks.c parser/pars_c.c \
		parser/pars_ea.c parser/pars_f.c \
		parser/pars_map.c parser/pars_no.c \
		parser/pars_param.c parser/pars_r.c \
		parser/pars_so.c parser/pars_sprite.c \
		parser/pars_utils.c parser/pars_we.c parser/parser.c \
		parser/search_no_wall.c get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c ft_split.c ft_substr.c\
		fn_paint_life.c ft_itoa.c

all: $(NAME)

$(NAME): $(SRC) $(HEAD)
	$(CC) $(SRC) -o $(NAME) libmlx.dylib

clean:
	rm -rf Screen\ \Shot.bmp

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re