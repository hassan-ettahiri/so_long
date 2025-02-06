#ifndef SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
#include "../mlx_linux/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

#define ROWS 22
#define COLS 19

typedef struct s_img
{
	void *left_pacman;
	void *right_pacman;
	void *up_pacman;
	void *down_pacman;
	void *enemy;
	void *wall;
	void *coin;
	void *free_space;
	void *exit;
	void *left_wall;
	void *right_wall;
	int x;
	int y;
}t_image;

typedef struct s_vars {
	void		*mlx;
	void		*mlx_win;
	char		**map;
	char		**map_enemy;
	t_image		*img;
}				t_vars;

typedef struct s_gb
{
	void		*ptr;
	struct s_gb	*next;
}t_gb;

typedef struct s_enemy {
	int x;
	int y;
	struct s_enemy *next;
}	t_enemy;

size_t	ft_strlen(const char *s);
void	*ft_malloc(ssize_t len);
char	*ft_itoa(int n);

int ft_strcmp(const char *str1, const char *str2);
char	*ft_strjoin(char const *s1, char const *s2);
char	*alloc_and_free(char *buffer, char *fake_buffer);
char	*ft_strdup(const char *s1);
int		is_line(char *s);
char	*read_file(int fd, char *buffer);
char	*ft_get_line(char *buffer);
char	*ft_next_line(char *buffer);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);

#endif