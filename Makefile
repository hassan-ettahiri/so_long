CFLAGS = -Wall -Wextra -Werror -g
NAME = so_long
BONUS = so_long_bonus
SRC =	./solong_mandatory/so_long.c ./utils/ft_strcmp.c ./gnl/get_next_line.c ./gnl/get_next_line_util.c ./memory/memory_tracker.c ./utils/ft_split.c \
		./solong_mandatory/parsing/parsing1.c ./solong_mandatory/parsing/parsing2.c ./solong_mandatory/implementation/destroy_window.c ./solong_mandatory/implementation/key_move.c \
		./solong_mandatory/implementation/move_player_interface.c ./solong_mandatory/implementation/move_player_map.c ./solong_mandatory/implementation/put_image_to_window.c \
		./solong_mandatory/implementation/render.c
SRC_BONUS = ./solong_bonus/so_long_bonus.c ./utils/ft_strcmp.c ./gnl/get_next_line.c ./gnl/get_next_line_util.c ./memory/memory_tracker.c ./utils/ft_split.c ./utils/ft_itoa.c \
			./solong_bonus/parsing_bonus/parsing1.c ./solong_bonus/parsing_bonus/parsing2.c ./solong_bonus/implementation_bonus/animation_and_move_enemy.c \
			./solong_bonus/implementation_bonus/destroy_window.c ./solong_bonus/implementation_bonus/key_move.c ./solong_bonus/implementation_bonus/move_enemy_map.c \
			./solong_bonus/implementation_bonus/move_enemy.c ./solong_bonus/implementation_bonus/move_player_interface.c ./solong_bonus/implementation_bonus/move_player_map.c \
			./solong_bonus/implementation_bonus/render_enemy.c ./solong_bonus/implementation_bonus/render.c ./solong_bonus/implementation_bonus/set_images.c \
			./solong_bonus/implementation_bonus/set_images1.c


OBJS = ${SRC:.c=.o}
OBJS_BONUS = ${SRC_BONUS:.c=.o}

MLX_PATH = mlx_linux
MLX = $(MLX_PATH)/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(MLX) ./solong_mandatory/so_long.h
	$(CC) $(CFLAGS) $(OBJS) -Lmlx_linux -lmlx -lX11 -lXext -lbsd -lm -lz $(MLX) -o $(NAME)

bonus: $(OBJS_BONUS) $(MLX) ./solong_bonus/so_long_bonus.h
	$(CC) $(CFLAGS) $(OBJS_BONUS) -Lmlx_linux -lmlx -lX11 -lXext -lbsd -lm -lz  $(MLX) -o $(BONUS)

%.o: %.c ./solong_bonus/so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX):
	$(MAKE) -C $(MLX_PATH)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(BONUS) $(MLX)

re: fclean all