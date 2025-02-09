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

typedef struct s_img
{
	void *left_pacman;
	void *right_pacman;
	void *up_pacman;
	void *down_pacman;
	void *enemy;
	void *wall;
	void *coin[2];
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
	int current_frame;
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
int check_param(char* str);
int check_map(char* str);
int check_len(char** str);
int check_wall(char **map);
void find_player(char **map, int *x, int *y);
void floodfill(char **map, int x, int y);
int check_road_is_correct(char **map);
int check_wall_and_floodfill(char *map);
int check_file_and_map(char* str, char ***map2d);
void dimension(char **map, int *x, int *y);
void *add_xpm_file_suite(t_vars *va, int type, int width, int hight);
void *add_xpm_file(t_vars *va, int type, int width, int hight);
int ft_set_images(t_vars *va, t_image *img);
void ft_put_img_to_window(t_vars *va, t_image *img, char c);
void ft_put_images(t_vars *va, t_image *img, char** map2d);
void safe_destroy_image(void *mlx, void *img);
void destroy_images(t_vars *va);
void exit_game(t_vars *va, int er);
void move_up_interface(t_vars *va);
void move_down_interface(t_vars *va);
void move_left_interface(t_vars *va);
void move_right_interface(t_vars *va);
void rebuild_map(t_vars *va, int move);
void print_nbr(int nbr);
void add_moves_in_screen(t_vars *va, int move);
int render(t_vars *va, int move);
int all_coin_collected(char **map);
void move_up(t_vars *va);
void move_down(t_vars *va);
void move_left(t_vars *va);
void move_right(t_vars *va);
void	ft_key_press(int key, t_vars *va);
int	key_hook(int key, t_vars *va);
int ft_quit(t_vars *va);
void move_up_enemy_interface(t_vars *va, int x, int y);
void move_down_enemy_interface(t_vars *va, int x, int y);
void move_left_enemy_interface(t_vars *va, int x, int y);
void move_right_enemy_interface(t_vars *va, int x, int y);
void render_enemy(t_vars *va, int type, int x, int y);
void move_up_enemy(t_vars *va, t_enemy *enemy);
void move_down_enemy(t_vars *va, t_enemy *enemy);
void move_left_enemy(t_vars *va, t_enemy *enemy);
void move_right_enemy(t_vars *va, t_enemy *enemy);
void ft_move_enemy(t_vars *va, t_enemy *enemy);
void add_to_enemy(t_vars *va, t_enemy *enemy);
int get_all_enemy(t_vars *va, t_enemy **enemy);
void move_enemy(t_vars *va);
void	ft_coin_1(t_vars *vars);
void	ft_coin_2(t_vars *vars);
void	ft_animations(t_vars *vars);
int lhook_ino(t_vars *va);
void init_to_null(t_vars *va);
void implementation(char **map);


#endif