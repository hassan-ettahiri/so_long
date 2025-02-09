#include "../so_long_bonus.h"

void	move_up_enemy(t_vars *va, t_enemy *enemy)
{
	char	**map;

	map = va->map;
	if (map[enemy->y - 1][enemy->x] == '0')
	{
		map[enemy->y][enemy->x] = '0';
		map[enemy->y - 1][enemy->x] = 'H';
		enemy->y--;
		render_enemy(va, 1, enemy->x, enemy->y);
	}
	else if (map[enemy->y - 1][enemy->x] == 'P')
	{
		exit_game(va, 2);
	}
	else
		return ;
}

void	move_down_enemy(t_vars *va, t_enemy *enemy)
{
	char	**map;

	map = va->map;
	if (map[enemy->y + 1][enemy->x] == '0')
	{
		map[enemy->y][enemy->x] = '0';
		map[enemy->y + 1][enemy->x] = 'H';
		enemy->y++;
		render_enemy(va, 2, enemy->x, enemy->y);
	}
	else if (map[enemy->y + 1][enemy->x] == 'P')
	{
		exit_game(va, 2);
	}
	else
		return ;
}

void	move_left_enemy(t_vars *va, t_enemy *enemy)
{
	char	**map;

	map = va->map;
	if (map[enemy->y][enemy->x - 1] == '0')
	{
		map[enemy->y][enemy->x] = '0';
		map[enemy->y][enemy->x - 1] = 'H';
		enemy->x--;
		render_enemy(va, 3, enemy->x, enemy->y);
	}
	else if (map[enemy->y][enemy->x - 1] == 'P')
	{
		exit_game(va, 2);
	}
	else
		return ;
}

void	move_right_enemy(t_vars *va, t_enemy *enemy)
{
	char	**map;

	map = va->map;
	if (map[enemy->y][enemy->x + 1] == '0')
	{
		map[enemy->y][enemy->x] = '0';
		map[enemy->y][enemy->x + 1] = 'H';
		enemy->x++;
		render_enemy(va, 4, enemy->x, enemy->y);
	}
	else if (map[enemy->y][enemy->x + 1] == 'P')
	{
		exit_game(va, 2);
	}
	else
		return ;
}

void	ft_move_enemy(t_vars *va, t_enemy *enemy)
{
	int	i;

	i = rand();
	if (i % 4 == 0)
		move_up_enemy(va, enemy);
	if (i % 4 == 1)
		move_down_enemy(va, enemy);
	if (i % 4 == 2)
		move_left_enemy(va, enemy);
	if (i % 4 == 3)
		move_right_enemy(va, enemy);
}
