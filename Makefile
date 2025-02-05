CFLAGS = -Wall -Wextra -Werror -g
NAME = so_long
BONUS = so_long_bonus
SRC = so_long.c ft_strcmp.c ./gnl/get_next_line.c ./gnl/get_next_line_util.c ./memory/memory_tracker.c ft_split.c
SRC_BONUS = ./solong_bonus/so_long.c ./solong_bonus/ft_strcmp.c ./solong_bonus/gnl/get_next_line.c ./solong_bonus/gnl/get_next_line_util.c ./solong_bonus/memory/memory_tracker.c ./solong_bonus/ft_split.c ./solong_bonus/ft_itoa.c

OBJS = ${SRC:.c=.o}
OBJS_BONUS = ${SRC_BONUS:.c=.o}

MLX_PATH = mlx_linux
MLX = $(MLX_PATH)/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -lXext -lX11 -lm -lz $(MLX) -o $(NAME)

bonus: $(OBJS_BONUS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -lXext -lX11 -lm -lz $(MLX) -o $(BONUS)

%.o: %.c ./solong_bonus/so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX):
	$(MAKE) -C $(MLX_PATH)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(BONUS) $(MLX)

re: fclean all