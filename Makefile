CFLAGS = -Wall -Wextra -Werror -g
NAME = so_long
BONUS = so_long_bonus
SRC =	so_long.c ./utils/ft_strcmp.c ./utils/gnl/get_next_line.c ./utils/gnl/get_next_line_util.c ./memory/memory_tracker.c ./utils/ft_split.c \
		./utils/parsing/parsing1.c ./utils/parsing/parsing2.c ./utils/implementation/destroy_window.c ./utils/implementation/key_move.c \
		./utils/implementation/move_player_interface.c ./utils/implementation/move_player_map.c ./utils/implementation/put_image_to_window.c \
		./utils/implementation/render.c
SRC_BONUS = ./solong_bonus/so_long.c ./solong_bonus/ft_strcmp.c ./solong_bonus/gnl/get_next_line.c ./solong_bonus/gnl/get_next_line_util.c ./solong_bonus/memory/memory_tracker.c ./solong_bonus/ft_split.c ./solong_bonus/ft_itoa.c

OBJS = ${SRC:.c=.o}
OBJS_BONUS = ${SRC_BONUS:.c=.o}

MLX_PATH = mlx_linux
MLX = $(MLX_PATH)/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -Lmlx_linux -lmlx -lX11 -lXext -lbsd -lm -lz $(MLX) -o $(NAME)

bonus: $(OBJS_BONUS) $(MLX)
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