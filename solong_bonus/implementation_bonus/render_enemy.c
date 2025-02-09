#include "../so_long_bonus.h"

void move_up_enemy_interface(t_vars *va, int x, int y)
{
    mlx_put_image_to_window(va->mlx, va->mlx_win, va->img->enemy, x * 64, y * 64);
    mlx_put_image_to_window(va->mlx, va->mlx_win, va->img->free_space, x * 64, (y + 1) * 64);
}

void move_down_enemy_interface(t_vars *va, int x, int y)
{
    mlx_put_image_to_window(va->mlx, va->mlx_win, va->img->enemy, x * 64, y * 64);
    mlx_put_image_to_window(va->mlx, va->mlx_win, va->img->free_space, x * 64, (y - 1) * 64);
}

void move_left_enemy_interface(t_vars *va, int x, int y)
{
    mlx_put_image_to_window(va->mlx, va->mlx_win, va->img->enemy, x * 64, y * 64);
    mlx_put_image_to_window(va->mlx, va->mlx_win, va->img->free_space, (x + 1) * 64, y * 64);
}

void move_right_enemy_interface(t_vars *va, int x, int y)
{
    mlx_put_image_to_window(va->mlx, va->mlx_win, va->img->enemy, x * 64, y * 64);
    mlx_put_image_to_window(va->mlx, va->mlx_win, va->img->free_space, (x - 1) * 64, y * 64);
}

void render_enemy(t_vars *va, int type, int x, int y)
{
    if(type == 1)
        move_up_enemy_interface(va, x, y);
    if(type == 2)
        move_down_enemy_interface(va, x, y);
    if(type == 3)
        move_left_enemy_interface(va, x, y);
    if(type == 4)
        move_right_enemy_interface(va, x, y);
}