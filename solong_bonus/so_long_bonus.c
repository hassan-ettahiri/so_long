#include "so_long_bonus.h"

int	ft_quit(t_vars *va)
{
	exit_game(va, 3);
	return (0);
}

void	init_to_null(t_vars *va)
{
	va->img->coin[0] = NULL;
	va->img->coin[1] = NULL;
	va->img->down_pacman = NULL;
	va->img->enemy = NULL;
	va->img->exit = NULL;
	va->img->free_space = NULL;
	va->img->left_pacman = NULL;
	va->img->right_pacman = NULL;
	va->img->up_pacman = NULL;
	va->img->wall = NULL;
	va->img->left_wall = NULL;
	va->img->right_wall = NULL;
}

void	implementation(char **map)
{
	t_vars	va;
	int		x;
	int		y;

	va.mlx = mlx_init();
	if (!va.mlx)
		return ;
	init_to_null(&va);
	dimension(map, &x, &y);
	va.mlx_win = mlx_new_window(va.mlx, x * 64, y * 64, "PACMAN");
	if (!va.mlx_win)
		return ;
	va.map = map;
	render(&va, 0);
	mlx_hook(va.mlx_win, 2, 1, key_hook, &va);
	mlx_loop_hook(va.mlx, lhook_ino, &va);
	mlx_hook(va.mlx_win, 17, 0, ft_quit, &va);
	mlx_loop(va.mlx);
}

int	main(int ac, char **av)
{
	char	**map;

	if (ac != 2 || check_param(av[1]) == 0)
		return (write(2, "Error\nincorrect parameter\n", 26), ft_malloc(-1), 1);
	if (check_file_and_map(av[1], &map) == 0)
		return (write(2, "Error\nincorrect map\n", 21), ft_malloc(-1), 1);
	if (check_file_and_map(av[1], &map) == 2)
		return (write(2, "Error\nincorrect file\n", 22), ft_malloc(-1), 1);
	implementation(map);
	return (ft_malloc(-1), 0);
}
