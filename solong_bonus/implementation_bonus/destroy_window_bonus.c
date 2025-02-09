/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hettahir <hettahir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 03:59:51 by hettahir          #+#    #+#             */
/*   Updated: 2025/02/09 03:59:51 by hettahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	safe_destroy_image(void *mlx, void *img)
{
	if (mlx && img)
		mlx_destroy_image(mlx, img);
}

void	destroy_images(t_vars *va)
{
	safe_destroy_image(va->mlx, va->img->coin[0]);
	safe_destroy_image(va->mlx, va->img->coin[1]);
	safe_destroy_image(va->mlx, va->img->free_space);
	safe_destroy_image(va->mlx, va->img->left_pacman);
	safe_destroy_image(va->mlx, va->img->right_pacman);
	safe_destroy_image(va->mlx, va->img->up_pacman);
	safe_destroy_image(va->mlx, va->img->down_pacman);
	safe_destroy_image(va->mlx, va->img->exit);
	safe_destroy_image(va->mlx, va->img->wall);
	safe_destroy_image(va->mlx, va->img->enemy);
	safe_destroy_image(va->mlx, va->img->left_wall);
	safe_destroy_image(va->mlx, va->img->right_wall);
}

void	exit_game(t_vars *va, int er)
{
	destroy_images(va);
	mlx_destroy_window(va->mlx, va->mlx_win);
	mlx_destroy_display(va->mlx);
	free(va->mlx);
	ft_malloc(-1);
	if (er == 0)
	{
		write(2, "Error\n", 7);
		exit(1);
	}
	else if (er == 1)
		write(1, "you win !!\n", 12);
	else if (er == 2)
		write(1, "you lose !!\n", 13);
	else
		write(1, "end game\n", 10);
	exit(0);
}
