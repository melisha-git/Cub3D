NAME = cub3D

OS := $(shell uname -s)

CC = gcc -Wall -Wextra -Werror

ifeq ($(OS), Linux)
	MLX = minilibx_linux/
	LINKS = libmlx.a -lXext -lX11 -lm -lbsd
endif
ifeq ($(OS), Darwin)
	MLX = minilibx_mms/
	LINKS = libmlx.dylib
endif

SRC_DIR = src/

HEAD = $(SRC_DIR)cub.h $(SRC_DIR)cub_struct.h $(SRC_DIR)get_next_line/get_next_line.h

SRC = $(SRC_DIR)error.c $(SRC_DIR)fn_init_raycast.c \
		$(SRC_DIR)fn_save.c $(SRC_DIR)init_param.c \
		$(SRC_DIR)init_pos_sprite.c $(SRC_DIR)init_press_key.c \
		$(SRC_DIR)init_texture_card_p.c $(SRC_DIR)main.c $(SRC_DIR)move.c \
		$(SRC_DIR)my_mlx.c $(SRC_DIR)paint_background.c $(SRC_DIR)paint_sprite.c \
		$(SRC_DIR)raycasting.c $(SRC_DIR)research.c $(SRC_DIR)shadow.c $(SRC_DIR)sprites.c \
		$(SRC_DIR)turn.c $(SRC_DIR)work_of_color.c $(SRC_DIR)parser/init_color.c \
		$(SRC_DIR)parser/no_leaks.c $(SRC_DIR)parser/pars_c.c \
		$(SRC_DIR)parser/pars_ea.c $(SRC_DIR)parser/pars_f.c \
		$(SRC_DIR)parser/pars_map.c $(SRC_DIR)parser/pars_no.c \
		$(SRC_DIR)parser/pars_param.c $(SRC_DIR)parser/pars_r.c \
		$(SRC_DIR)parser/pars_so.c $(SRC_DIR)parser/pars_sprite.c \
		$(SRC_DIR)parser/pars_utils.c $(SRC_DIR)parser/pars_we.c $(SRC_DIR)parser/parser.c \
		$(SRC_DIR)parser/search_no_wall.c $(SRC_DIR)get_next_line/get_next_line.c \
		$(SRC_DIR)get_next_line/get_next_line_utils.c $(SRC_DIR)ft_split.c $(SRC_DIR)ft_substr.c\
		$(SRC_DIR)fn_paint_life.c $(SRC_DIR)ft_itoa.c

all: $(NAME)

$(NAME): $(SRC) $(HEAD)
	$(CC) $(SRC) -o $(NAME) $(LINKS)

clean:
	rm -rf Screen\ \Shot.bmp

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re