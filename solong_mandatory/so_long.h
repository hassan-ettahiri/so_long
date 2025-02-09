/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hettahir <hettahir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 04:00:35 by hettahir          #+#    #+#             */
/*   Updated: 2025/02/09 04:00:35 by hettahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../gnl/get_next_line.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

typedef struct s_img
{
	void		*left_pacman;
	void		*right_pacman;
	void		*up_pacman;
	void		*down_pacman;
	void		*wall;
	void		*coin;
	void		*free_space;
	void		*exit;
	int			x;
	int			y;
}				t_image;

typedef struct s_vars
{
	void		*mlx;
	void		*mlx_win;
	char		**map;
	t_image		*img;
}				t_vars;

typedef struct s_gb
{
	void		*ptr;
	struct s_gb	*next;
}				t_gb;

size_t			ft_strlen(const char *s);
void			*ft_malloc(ssize_t len);

int				ft_strcmp(const char *str1, const char *str2);
char			**ft_split(char const *s, char c);
int				check_param(char *str);
void			increment(char ch, int *e, int *p, int *c);
int				check_map(char *str);
int				check_len(char **str);
int				check_wall(char **map);
void			find_player(char **map, int *x, int *y);
void			floodfill(char **map, int x, int y);
int				check_road_is_correct(char **map);
int				check_wall_and_floodfill(char *map);
int				check_file_and_map(char *str, char ***map2d);
void			dimension(char **map, int *x, int *y);
void			*add_xpm_file(t_vars *va, int type, int width, int hight);
int				ft_set_images(t_vars *va, t_image *img);
void			safe_destroy_image(void *mlx, void *img);
void			destroy_images(t_vars *va);
void			exit_game(t_vars *va, int er);
int				ft_put_img_to_window(t_vars *va, t_image *img, char c);
void			ft_put_images(t_vars *va, t_image *img, char **map2d);
void			move_up_interface(t_vars *va);
void			move_down_interface(t_vars *va);
void			move_left_interface(t_vars *va);
void			move_right_interface(t_vars *va);
void			rebuild_map(t_vars *va, int move);
void			print_nbr(int nbr);
int				render(t_vars *va, int move);
int				all_coin_collected(char **map);
void			move_up(t_vars *va);
void			move_down(t_vars *va);
void			move_left(t_vars *va);
void			move_right(t_vars *va);
void			ft_key_press(int key, t_vars *va);
int				key_hook(int key, t_vars *va);
int				ft_quit(t_vars *va);
void			init_to_null(t_vars *va);
void			implementation(char **map);

#endif