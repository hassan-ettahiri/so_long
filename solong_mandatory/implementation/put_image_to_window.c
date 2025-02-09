/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image_to_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hettahir <hettahir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 04:00:25 by hettahir          #+#    #+#             */
/*   Updated: 2025/02/09 04:00:25 by hettahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	if (type == 8)
		return (mlx_xpm_file_to_image(va->mlx, "./images/exit.xpm", &width,
				&hight));
	return (NULL);
}

int	ft_set_images(t_vars *va, t_image *img)
{
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
	if (!img->wall)
		return (0);
	img->coin = add_xpm_file(va, 6, 64, 64);
	if (!img->coin)
		return (0);
	img->free_space = add_xpm_file(va, 7, 64, 64);
	if (!img->free_space)
		return (0);
	img->exit = add_xpm_file(va, 8, 64, 64);
	if (!img->exit)
		return (0);
	return (1);
}

int	ft_put_img_to_window(t_vars *va, t_image *img, char c)
{
	if (c == '0')
		return (mlx_put_image_to_window(va->mlx, va->mlx_win, img->free_space,
				img->x, img->y));
	else if (c == '1')
		return (mlx_put_image_to_window(va->mlx, va->mlx_win, img->wall, img->x,
				img->y));
	else if (c == 'E')
		return (mlx_put_image_to_window(va->mlx, va->mlx_win, img->exit, img->x,
				img->y));
	else if (c == 'C')
		return (mlx_put_image_to_window(va->mlx, va->mlx_win, img->coin, img->x,
				img->y));
	else if (c == 'P')
		return (mlx_put_image_to_window(va->mlx, va->mlx_win, img->right_pacman,
				img->x, img->y));
	return (0);
}

void	ft_put_images(t_vars *va, t_image *img, char **map2d)
{
	int		x;
	int		y;
	char	**map;
	int		f;

	y = 0;
	map = map2d;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			img->x = x * 64;
			img->y = y * 64;
			f = ft_put_img_to_window(va, img, map[y][x]);
			if (!f)
				exit_game(va, 0);
			x++;
		}
		y++;
	}
}
