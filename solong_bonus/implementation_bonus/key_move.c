#include "../so_long_bonus.h"

void	ft_key_press(int key, t_vars *va)
{
	if (key == XK_Up || key == XK_w)
		move_up(va);
	else if (key == XK_Down || key == XK_s)
		move_down(va);
	else if (key == XK_Left || key == XK_a)
		move_left(va);
	else if (key == XK_Right || key == XK_d)
		move_right(va);
	else
		return ;
}

int	key_hook(int key, t_vars *va)
{
	if (key == XK_Escape && va->mlx)
		exit_game(va, 3);
	else
		ft_key_press(key, va);
	return (0);
}
