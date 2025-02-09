#include "../so_long.h"

void	safe_destroy_image(void *mlx, void *img)
{
	if (mlx && img)
		mlx_destroy_image(mlx, img);
}

void	destroy_images(t_vars *va)
{
	safe_destroy_image(va->mlx, va->img->coin);
	safe_destroy_image(va->mlx, va->img->free_space);
	safe_destroy_image(va->mlx, va->img->left_pacman);
	safe_destroy_image(va->mlx, va->img->right_pacman);
	safe_destroy_image(va->mlx, va->img->up_pacman);
	safe_destroy_image(va->mlx, va->img->down_pacman);
	safe_destroy_image(va->mlx, va->img->exit);
	safe_destroy_image(va->mlx, va->img->wall);
}

void	exit_game(t_vars *va, int er)
{
	destroy_images(va);
	mlx_destroy_display(va->mlx);
	mlx_destroy_window(va->mlx, va->mlx_win);
	free(va->mlx);
	ft_malloc(-1);
	if (er == 0)
		write(2, "Error\n", 7);
	else
		write(1, "end game\n", 10);
	exit(0);
}
