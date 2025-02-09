/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_interface.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hettahir <hettahir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 03:59:56 by hettahir          #+#    #+#             */
/*   Updated: 2025/02/09 03:59:56 by hettahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	move_up_interface(t_vars *va)
{
	int	x;
	int	y;

	find_player(va->map, &x, &y);
	mlx_put_image_to_window(va->mlx, va->mlx_win, va->img->up_pacman, x * 64, y
		* 64);
	mlx_put_image_to_window(va->mlx, va->mlx_win, va->img->free_space, x * 64,
		(y + 1) * 64);
}

void	move_down_interface(t_vars *va)
{
	int	x;
	int	y;

	find_player(va->map, &x, &y);
	mlx_put_image_to_window(va->mlx, va->mlx_win, va->img->down_pacman, x * 64,
		y * 64);
	mlx_put_image_to_window(va->mlx, va->mlx_win, va->img->free_space, x * 64,
		(y - 1) * 64);
}

void	move_left_interface(t_vars *va)
{
	int	x;
	int	y;

	find_player(va->map, &x, &y);
	mlx_put_image_to_window(va->mlx, va->mlx_win, va->img->left_pacman, x * 64,
		y * 64);
	mlx_put_image_to_window(va->mlx, va->mlx_win, va->img->free_space, (x + 1)
		* 64, y * 64);
}

void	move_right_interface(t_vars *va)
{
	int	x;
	int	y;

	find_player(va->map, &x, &y);
	mlx_put_image_to_window(va->mlx, va->mlx_win, va->img->right_pacman, x * 64,
		y * 64);
	mlx_put_image_to_window(va->mlx, va->mlx_win, va->img->free_space, (x - 1)
		* 64, y * 64);
}

void	rebuild_map(t_vars *va, int move)
{
	if (move == 1)
		move_up_interface(va);
	else if (move == 2)
		move_down_interface(va);
	else if (move == 3)
		move_left_interface(va);
	else if (move == 4)
		move_right_interface(va);
}
