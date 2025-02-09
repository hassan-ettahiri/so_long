#include "../so_long_bonus.h"

void	ft_coin_1(t_vars *vars)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	map = vars->map;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->img->coin[1], x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	ft_coin_2(t_vars *vars)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	map = vars->map;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->img->coin[0], x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	ft_animations(t_vars *vars)
{
	static int	i;
	static int	x;

	if (i % 2 == 0 && x % 5 == 0)
		ft_coin_1(vars);
	else if (i % 2 != 0 && x % 5 == 0)
		ft_coin_2(vars);
	x++;
	i++;
}

int	lhook_ino(t_vars *va)
{
	static int	x;

	if (x % 3000 == 0)
	{
		if (x % 27000 == 0)
			move_enemy(va);
		ft_animations(va);
	}
	x++;
	return (0);
}
