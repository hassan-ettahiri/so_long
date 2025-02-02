CFLAGS = -Wall -Wextra -Werror
NAME = so_long
SRC = so_long.c ft_strcmp.c ./gnl/get_next_line.c ./gnl/get_next_line_util.c ./memory/memory_tracker.c ft_split.c

OBJS = ${SRC:.c=.o}

MLX_PATH = mlx_linux
MLX = $(MLX_PATH)/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -lXext -lX11 -lm -lz $(MLX) -o $(NAME)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX):
	$(MAKE) -C $(MLX_PATH)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(MLX)

re: fclean all