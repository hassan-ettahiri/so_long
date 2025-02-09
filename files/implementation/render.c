#include "../../so_long.h"

void	dimension(char **map, int *x, int *y)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	*y = i;
	i = 0;
	while (map[0][i])
		i++;
	*x = i;
}

void	print_nbr(int nbr)
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

int	render(t_vars *va, int move)
{
	static int	status;
	static int	cpt;

	if (move == 0)
	{
		status = ft_set_images(va, va->img);
		if (status)
			ft_put_images(va, va->img, va->map);
		else
			exit_game(va, 0);
	}
	print_nbr(cpt);
	write(1, "\n", 1);
	cpt++;
	rebuild_map(va, move);
	return (0);
}
