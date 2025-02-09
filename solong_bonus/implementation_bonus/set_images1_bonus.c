/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hettahir <hettahir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 04:00:07 by hettahir          #+#    #+#             */
/*   Updated: 2025/02/09 04:00:07 by hettahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	*add_xpm_file_suite(t_vars *va, int type, int width, int hight)
{
	if (type == 8)
		return (mlx_xpm_file_to_image(va->mlx, "./images/exit.xpm", &width,
				&hight));
	if (type == 9)
		return (mlx_xpm_file_to_image(va->mlx, "./images/enemy.xpm", &width,
				&hight));
	if (type == 10)
		return (mlx_xpm_file_to_image(va->mlx, "./images/left_wall.xpm", &width,
				&hight));
	if (type == 11)
		return (mlx_xpm_file_to_image(va->mlx, "./images/right_wall.xpm",
				&width, &hight));
	if (type == 12)
		return (mlx_xpm_file_to_image(va->mlx, "./images/coin1.xpm", &width,
				&hight));
	return (NULL);
}

void	*add_xpm_file(t_vars *va, int type, int width, int hight)
{
	if (type == 1)
		return (mlx_xpm_file_to_image(va->mlx, "./images/down_pacman.xpm",
				&width, &hight));
	if (type == 2)
		return (mlx_xpm_file_to_image(va->mlx, "./images/left_pacman.xpm",
				&width, &hight));
	if (type == 3)
		return (mlx_xpm_file_to_image(va->mlx, "./images/right_pacman.xpm",
				&width, &hight));
	if (type == 4)
		return (mlx_xpm_file_to_image(va->mlx, "./images/up_pacman.xpm", &width,
				&hight));
	if (type == 5)
		return (mlx_xpm_file_to_image(va->mlx, "./images/wall.xpm", &width,
				&hight));
	if (type == 6)
		return (mlx_xpm_file_to_image(va->mlx, "./images/coin.xpm", &width,
				&hight));
	if (type == 7)
		return (mlx_xpm_file_to_image(va->mlx, "./images/free_space.xpm",
				&width, &hight));
	return (add_xpm_file_suite(va, type, width, hight));
	return (NULL);
}

int	ft_set_images_suite(t_vars *va, t_image *img)
{
	if (!img->wall)
		return (0);
	img->coin[0] = add_xpm_file(va, 6, 64, 64);
	if (!img->coin[0])
		return (0);
	img->coin[1] = add_xpm_file(va, 12, 64, 64);
	if (!img->coin[1])
		return (0);
	img->free_space = add_xpm_file(va, 7, 64, 64);
	if (!img->free_space)
		return (0);
	img->exit = add_xpm_file(va, 8, 64, 64);
	if (!img->exit)
		return (0);
	img->enemy = add_xpm_file(va, 9, 64, 64);
	if (!img->enemy)
		return (0);
	img->left_wall = add_xpm_file(va, 10, 64, 64);
	if (!img->left_wall)
		return (0);
	img->right_wall = add_xpm_file(va, 11, 64, 64);
	if (!img->right_wall)
		return (0);
	return (1);
}

int	ft_set_images(t_vars *va, t_image *img)
{
	int	i;

	img->down_pacman = add_xpm_file(va, 1, 64, 64);
	if (!img->down_pacman)
		return (0);
	img->left_pacman = add_xpm_file(va, 2, 64, 64);
	if (!img->left_pacman)
		return (0);
	img->right_pacman = add_xpm_file(va, 3, 64, 64);
	if (!img->right_pacman)
		return (0);
	img->up_pacman = add_xpm_file(va, 4, 64, 64);
	if (!img->up_pacman)
		return (0);
	img->wall = add_xpm_file(va, 5, 64, 64);
	i = ft_set_images_suite(va, img);
	if (i == 0)
		return (0);
	return (1);
}
