#include "../so_long_bonus.h"

void dimension(char **map, int *x, int *y)
{
    int i;

    i = 0;
    while(map[i])
        i++;
    *y = i;
    i = 0;
    while(map[0][i])
        i++;
    *x = i;
}

void ft_put_img_to_window(t_vars *va, t_image *img, char c)
{
    if(c == '0')
        mlx_put_image_to_window(va->mlx, va->mlx_win, img->free_space, img->x, img->y);
    else if(c == '1')
        mlx_put_image_to_window(va->mlx, va->mlx_win, img->wall, img->x, img->y);
    else if(c == 'E')
        mlx_put_image_to_window(va->mlx, va->mlx_win, img->exit, img->x, img->y);
    else if(c == 'C')
        mlx_put_image_to_window(va->mlx, va->mlx_win, img->coin[0], img->x, img->y);
    else if(c == 'P')
        mlx_put_image_to_window(va->mlx, va->mlx_win, img->right_pacman, img->x, img->y);
    else if(c == 'H')
        mlx_put_image_to_window(va->mlx, va->mlx_win, img->enemy, img->x, img->y);
}

void ft_put_images(t_vars *va, t_image *img, char** map2d)
{
    int x;
    int y;
    char **map;

    y = 0;
    map = map2d;
    while(map[y]){
        x = 0;
        while(map[y][x]){
            img->x = x * 64;
            img->y = y * 64;
            ft_put_img_to_window(va, img, map[y][x]);
            x++;
        }
        y++;
    }
}