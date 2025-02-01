CFLAGS = -Wall -Wextra -Werror
NAME = so_long
SRC = 	ft_strcmp.c so_long.c ./gnl/get_next_line.c ./gnl/get_next_line_util.c ./memory/memory_tracker.c ft_split.c

OBJS = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJS) so_long.h
	cc ${CFLAGS} $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(CHECHER)

re: fclean all