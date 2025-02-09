#include "../so_long_bonus.h"

void print_nbr(int nbr)
{
    long long	nb;
	char		chiffre;

	nb = nbr;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb < 10)
	{
		chiffre = nb + '0';
		write(1, &chiffre, 1);
	}
	if (nb > 9)
	{
		print_nbr(nb / 10);
		chiffre = (nb % 10) + '0';
		write(1, &chiffre, 1);
	}
}

void add_moves_in_screen(t_vars *va, int move)
{
    char* number;
    number = ft_itoa(move);
    mlx_put_image_to_window(va->mlx, va->mlx_win, va->img->right_wall, 0, 0);
    mlx_put_image_to_window(va->mlx, va->mlx_win, va->img->left_wall, 64, 0);
    mlx_string_put(va->mlx, va->mlx_win, 27, 35, 0xFFFFFF, "M");
    mlx_string_put(va->mlx, va->mlx_win, 37, 35, 0xFFFFFF, "o");
    mlx_string_put(va->mlx, va->mlx_win, 47, 35, 0xFFFFFF, "v");
    mlx_string_put(va->mlx, va->mlx_win, 57, 35, 0xFFFFFF, "e");
    mlx_string_put(va->mlx, va->mlx_win, 67, 35, 0xFFFFFF, "s");
    mlx_string_put(va->mlx, va->mlx_win, 77, 35, 0xFFFFFF, ":");
    mlx_string_put(va->mlx, va->mlx_win, 90, 35, 0xFFFFFF, number);
}

int render(t_vars *va, int move)
{
    static int  status;
    static int  cpt;

    if(move == 0){
        status = ft_set_images(va, va->img);
        if(status){
            ft_put_images(va, va->img, va->map);
        }
        else
            exit_game(va,  0);
    }
    print_nbr(cpt);
    write(1, "\n", 1);
    add_moves_in_screen(va, cpt);
    cpt++;
    rebuild_map(va, move);
    return 0;
}