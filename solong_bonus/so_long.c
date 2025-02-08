#include <unistd.h>
#include "so_long.h"

int check_param(char* str)
{
    int c = ft_strlen(str);

    if(c < 4 || ft_strcmp(&str[c - 4], ".ber") != 0)
        return 0;
    return 1;
}
int check_map(char* str)
{
    int i;
    int e;
    int p;
    int c;
    int h;

    h = 0;
    i = 0;
    e = 0;
    p = 0;
    c = 0;
    while (str[i])
    {
        if(str[i] == 'E' || str[i] == '\n' || str[i] == 'P' || str[i] == 'C' || str[i] == '0' || str[i] == '1' || str[i] == 'H')
        {
            if((str[i] == '\n' && str[i + 1] == '\n') || ((i == 0 || str[i + 1] == '\0') && str[i] == '\n'))
                return 0;
            else if(str[i] == 'E')
                e++;
            else if(str[i] == 'P')
                p++;
            else if(str[i] == 'C')
                c++;
            else if(str[i] == 'H')
                h++;
        }
        else
            return 0;
        i++;
    }
    if(e != 1 || p != 1 || c < 1 || h < 1)
        return 0;
    return 1;
}

int check_len(char** str)
{
    int i;

    i = 0;
    while(str[i + 1]){
        if(ft_strlen(str[i]) != ft_strlen(str[i + 1]) || ft_strlen(str[i]) > 60)
            return 0;
        i++;
    }
    if(i > 31)
        return 0;
    return 1;
}

int check_wall(char **map)
{
    int i;
    int j;

    i = 0;
    while(map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if((i == 0 || !map[i + 1]) && map[i][j] != '1')
                return 0;
            if((j == 0 || !map[i][j + 1]) && map[i][j] != '1')
                return 0;
            j++;
        } 
        i++;
    }
    return 1;
}

void find_player(char **map, int *x, int *y)
{
    int i;
    int j;

    i = 0;
    while(map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if(map[i][j] == 'P'){
                *y = i;
                *x = j;
            }
            j++;
        } 
        i++;
    }
}

void floodfill(char **map, int x, int y)
{
	if (map[y][x] == '0' || map[y][x] == 'E'
		|| map[y][x] == 'C' || map[y][x] == 'P' || map[y][x] == 'H')
	{
		if (map[y][x] == 'E' || map[y][x] == 'H')
		{
			map[y][x] = 'X';
			return ;
		}	
		map[y][x] = 'X';
	}
	else
		return ;
	floodfill(map, x - 1, y);
	floodfill(map, x + 1, y);
	floodfill(map, x, y - 1);
	floodfill(map, x, y + 1);
}

int check_road_is_correct(char **map)
{
    int i;
    int j;

    i = 0;
    while(map[i]){
        j = 0;
        while(map[i][j]){
            if(!(map[i][j] == 'X' || map[i][j] == '1' || map[i][j] == '0' || map[i][j] == 'H'))
                return 0;
            j++;
        }
        i++;
    }
    return 1;
}

int check_wall_and_floodfill(char *map)
{
    char **map2d;
    int x;
    int y;

    map2d = ft_split(map, '\n');
    if(!map2d || check_len(map2d) == 0 || check_wall(map2d) == 0)
        return 0;
    find_player(map2d, &x, &y);
    floodfill(map2d, x, y);
    if(check_road_is_correct(map2d) == 0)
        return 0;
    return 1;
}

int check_file_and_map(char* str, char ***map2d)
{
    int fd;
    char *line;
    char *map;

    map = NULL;
    fd = open(str, O_RDONLY);
    if(fd == -1)
        return 2;
    line = get_next_line(fd);
    if(!line)
        return 0;
    while(line)
    {
        map = ft_strjoin(map, line);
        line = get_next_line(fd);
    }
    close(fd);
    if(check_map(map) == 0 || check_wall_and_floodfill(map) == 0)
        return 0;
    *map2d = ft_split(map, '\n');
    if(!(*map2d))
        return 0;
    return 1;
}

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

void *add_xpm_file(t_vars *va, int type, int width, int hight)
{
    if(type == 1)
        return (mlx_xpm_file_to_image(va->mlx, "./images/down_pacman.xpm", &width, &hight));
    if(type == 2)
        return (mlx_xpm_file_to_image(va->mlx, "./images/left_pacman.xpm", &width, &hight));
    if(type == 3)
        return (mlx_xpm_file_to_image(va->mlx, "./images/right_pacman.xpm", &width, &hight));
    if(type == 4)
        return (mlx_xpm_file_to_image(va->mlx, "./images/up_pacman.xpm", &width, &hight));
    if(type == 5)
        return (mlx_xpm_file_to_image(va->mlx, "./images/wall.xpm", &width, &hight));
    if(type == 6)
        return (mlx_xpm_file_to_image(va->mlx, "./images/coin.xpm", &width, &hight));
    if(type == 7)
        return (mlx_xpm_file_to_image(va->mlx, "./images/free_space.xpm", &width, &hight));
    if(type == 8)
        return (mlx_xpm_file_to_image(va->mlx, "./images/exit.xpm", &width, &hight));
    if(type == 9)
        return (mlx_xpm_file_to_image(va->mlx, "./images/enemy.xpm", &width, &hight));
    if(type == 10)
        return (mlx_xpm_file_to_image(va->mlx, "./images/left_wall.xpm", &width, &hight));
    if(type == 11)
        return (mlx_xpm_file_to_image(va->mlx, "./images/right_wall.xpm", &width, &hight));
    if(type == 12)
        return (mlx_xpm_file_to_image(va->mlx, "./images/coin1.xpm", &width, &hight));
    if(type == 13)
        return (mlx_xpm_file_to_image(va->mlx, "./images/coin2.xpm", &width, &hight));
    return NULL;
}

int ft_set_images(t_vars *va, t_image *img)
{
    img->down_pacman = add_xpm_file(va, 1, 64, 64);
    if(!img->down_pacman)
        return 0;
    img->left_pacman = add_xpm_file(va, 2, 64, 64);
    if(!img->left_pacman)
        return 0;
    img->right_pacman = add_xpm_file(va, 3, 64, 64);
    if(!img->right_pacman)
        return 0;
    img->up_pacman = add_xpm_file(va, 4, 64, 64);
    if(!img->up_pacman)
        return 0;
    img->wall = add_xpm_file(va, 5, 64, 64);
    if(!img->wall)
        return 0;
    img->coin[0] = add_xpm_file(va, 6, 64, 64);
    if(!img->coin[0])
        return 0;
    img->coin[1] = add_xpm_file(va, 12, 64, 64);
    if(!img->coin[1])
        return 0;
    img->coin[2] = add_xpm_file(va, 13, 64, 64);
    if(!img->coin[2])
        return 0;
    img->free_space = add_xpm_file(va, 7, 64, 64);
    if(!img->free_space)
        return 0;
    img->exit = add_xpm_file(va, 8, 64, 64);
    if(!img->exit)
        return 0;
    img->enemy = add_xpm_file(va, 9, 64, 64);
    if(!img->enemy)
        return 0;
    img->left_wall = add_xpm_file(va, 10, 64, 64);
    if(!img->left_wall)
        return 0;
    img->right_wall = add_xpm_file(va, 11, 64, 64);
    if(!img->right_wall)
        return 0;
    return 1;
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

void safe_destroy_image(void *mlx, void *img)
{
    if (mlx && img)
        mlx_destroy_image(mlx, img);
}

void destroy_images(t_vars *va)
{
    safe_destroy_image(va->mlx, va->img->coin[0]);
    safe_destroy_image(va->mlx, va->img->coin[1]);
    safe_destroy_image(va->mlx, va->img->coin[2]);
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


void exit_game(t_vars *va, int er)
{
    destroy_images(va);
    mlx_destroy_window(va->mlx, va->mlx_win);
    mlx_destroy_display(va->mlx);
    free(va->mlx);
    ft_malloc(-1);
    if (er == 0)
    {
        write (2, "Error\n", 7);
        exit(1);
    }
    else if(er == 1)
        write(1, "you win !!\n", 12);
    else if(er == 2)
        write(1, "you lose !!\n", 13);
    else
        write(1, "end game\n", 10);
    exit(0);
}

void move_up_interface(t_vars *va)
{
    int x;
    int y;

    find_player(va->map, &x, &y);
    mlx_put_image_to_window(va->mlx, va->mlx_win, va->img->up_pacman, x * 64, y * 64);
    mlx_put_image_to_window(va->mlx, va->mlx_win, va->img->free_space, x * 64, (y + 1) * 64);
}

void move_down_interface(t_vars *va)
{
    int x;
    int y;

    find_player(va->map, &x, &y);
    mlx_put_image_to_window(va->mlx, va->mlx_win, va->img->down_pacman, x * 64, y * 64);
    mlx_put_image_to_window(va->mlx, va->mlx_win, va->img->free_space, x * 64, (y - 1) * 64);
}

void move_left_interface(t_vars *va)
{
    int x;
    int y;

    find_player(va->map, &x, &y);
    mlx_put_image_to_window(va->mlx, va->mlx_win, va->img->left_pacman, x * 64, y * 64);
    mlx_put_image_to_window(va->mlx, va->mlx_win, va->img->free_space, (x + 1) * 64, y * 64);
}

void move_right_interface(t_vars *va)
{
    int x;
    int y;

    find_player(va->map, &x, &y);
    mlx_put_image_to_window(va->mlx, va->mlx_win, va->img->right_pacman, x * 64, y * 64);
    mlx_put_image_to_window(va->mlx, va->mlx_win, va->img->free_space, (x - 1) * 64, y * 64);
}

void rebuild_map(t_vars *va, int move)
{
    if(move == 1)
        move_up_interface(va);
    else if(move == 2)
        move_down_interface(va);
    else if(move == 3)
        move_left_interface(va);
    else if(move == 4)
        move_right_interface(va);
}

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

int all_coin_collected(char **map)
{
    int i = 0;
    int j = 0;

    while(map[i]){
        j = 0;
        while(map[i][j]){
            if(map[i][j] == 'C')
                return 0;
            j++;
        }
        i++;
    }
    return 1;
}

void move_up(t_vars *va)
{
    char **map;
    int x;
    int y;

    map = va->map;
    find_player(map, &x, &y);
    if(map[y - 1][x] == '0' || map[y - 1][x] == 'C'){
        map[y][x] = '0';
        map[y - 1][x] = 'P';
        render(va, 1);
    }
    if(map[y - 1][x] == 'E' && all_coin_collected(map) == 1)
    {
            exit_game(va,  1);
    }
    if(map[y - 1][x] == 'H')
        exit_game(va, 2);
}

void move_down(t_vars *va)
{
    char **map;
    int x;
    int y;

    map = va->map;
    find_player(map, &x, &y);
    if(map[y + 1][x] == '0' || map[y + 1][x] == 'C'){
        map[y][x] = '0';
        map[y + 1][x] = 'P';
        render(va, 2);
    }
    if(map[y + 1][x] == 'E' && all_coin_collected(map) == 1)
    {
            exit_game(va,  1);
    }
    if(map[y + 1][x] == 'H')
        exit_game(va, 2);
}

void move_left(t_vars *va)
{
    char **map;
    int x;
    int y;

    map = va->map;
    find_player(map, &x, &y);
    if(map[y][x - 1] == '0' || map[y][x - 1] == 'C'){
        map[y][x] = '0';
        map[y][x - 1] = 'P';
        render(va, 3);
    }
    if(map[y][x - 1] == 'E' && all_coin_collected(map) == 1)
    {
            exit_game(va,  1);
    }
    if(map[y][x - 1] == 'H')
        exit_game(va, 2);
}

void move_right(t_vars *va)
{
    char **map;
    int x;
    int y;

    map = va->map;
    find_player(map, &x, &y);
    if(map[y][x + 1] == '0' || map[y][x + 1] == 'C'){
        map[y][x] = '0';
        map[y][x + 1] = 'P';
        render(va, 4);
    }
    if(map[y][x + 1] == 'E' && all_coin_collected(map) == 1)
    {
            exit_game(va,  1);
    }
    if(map[y][x + 1] == 'H')
        exit_game(va, 2);
}

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
		exit_game(va,  3);
	else
		ft_key_press(key, va);
	return (0);
}

int ft_quit(t_vars *va){
    exit_game(va,  3);
    return 0;
}

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

void move_up_enemy(t_vars *va, t_enemy *enemy)
{
    char **map;

    map = va->map;
    if(map[enemy->y - 1][enemy->x] == '0'){
        map[enemy->y][enemy->x] = '0';
        map[enemy->y - 1][enemy->x] = 'H';
        enemy->y--;
        render_enemy(va, 1, enemy->x, enemy->y);
    }
    else if(map[enemy->y - 1][enemy->x] == 'P')
    {
        exit_game(va,  2);
    }
    else
        return;
}

void move_down_enemy(t_vars *va, t_enemy *enemy)
{
    char **map;

    map = va->map;
    if(map[enemy->y + 1][enemy->x] == '0'){
        map[enemy->y][enemy->x] = '0';
        map[enemy->y + 1][enemy->x] = 'H';
        enemy->y++;
        render_enemy(va, 2, enemy->x, enemy->y);
    }
    else if(map[enemy->y + 1][enemy->x] == 'P')
    {
        exit_game(va,  2);
    }
    else
        return;
}

void move_left_enemy(t_vars *va, t_enemy *enemy)
{
    char **map;

    map = va->map;
    if(map[enemy->y][enemy->x - 1] == '0'){
        map[enemy->y][enemy->x] = '0';
        map[enemy->y][enemy->x - 1] = 'H';
        enemy->x--;
        render_enemy(va, 3, enemy->x, enemy->y);
    }
    else if(map[enemy->y][enemy->x - 1] == 'P')
    {
        exit_game(va,  2);
    }
    else
        return;
}

void move_right_enemy(t_vars *va, t_enemy *enemy)
{
    char **map;

    map = va->map;
    if(map[enemy->y][enemy->x + 1] == '0'){
        map[enemy->y][enemy->x] = '0';
        map[enemy->y][enemy->x + 1] = 'H';
        enemy->x++;
        render_enemy(va, 4, enemy->x, enemy->y);
    }
    else if(map[enemy->y][enemy->x + 1] == 'P')
    {
        exit_game(va,  2);
    }
    else
        return;
}

void ft_move_enemy(t_vars *va, t_enemy *enemy)
{
    int i;

    i = rand();
    if(i%4 == 0)
        move_up_enemy(va, enemy);
    if(i%4 == 1)
        move_down_enemy(va, enemy);
    if(i%4 == 2)
        move_left_enemy(va, enemy);
    if(i%4 == 3)
        move_right_enemy(va, enemy);
}

void add_to_enemy(t_vars *va, t_enemy *enemy)
{
    int i;
    int j;
    int c;

    i = 0;
    c = 0;
    while(va->map[i])
    {
        j = 0;
        while(va->map[i][j])
        {
            if(va->map[i][j] == 'H')
            {
                enemy[c].x = j;
                enemy[c].y = i;
                c++;
            }
            j++;
        }
        i++;
    }
}

int get_all_enemy(t_vars *va, t_enemy **enemy)
{
    int i;
    int j;
    int cpt;

    i = 0;
    cpt = 0;
    while(va->map[i])
    {
        j = 0;
        while(va->map[i][j])
        {
            if(va->map[i][j] == 'H')
                cpt++;
            j++;
        }
        i++;
    }
    *enemy = ft_malloc((cpt) * sizeof(t_enemy));
    add_to_enemy(va, *enemy);
    return cpt;
}

void move_enemy(t_vars *va)
{
    int c;
    t_enemy *enemy;
    int i;

    i = 0;
    enemy = NULL;
    c = get_all_enemy(va, &enemy);
    while(i < c)
    {
        ft_move_enemy(va, &enemy[i]);
        i++;
    }
}

void	ft_show_apple(t_vars *vars)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	map = vars->map;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx,
					vars->mlx_win, vars->img->coin[1], x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	ft_hide_apple(t_vars *vars)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	map = vars->map;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->img->coin[0], x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	ft_animations(t_vars *vars)
{
	static int	i;
	static int	x;

	if (i % 2 == 0 && x % 5 == 0)
		ft_hide_apple(vars);
	else if (i % 2 != 0 && x % 5 == 0)
		ft_show_apple(vars);
	x++;
	i++;
}


int lhook_ino(t_vars *va)
{
	static int	x;

	if (x % 3000 == 0)
	{
        if(x%27000 == 0)
		    move_enemy(va);
        ft_animations(va);
	}
	x++;
	return (0);
}

void init_to_null(t_vars *va)
{
    va->img->coin[0] = NULL;
    va->img->coin[1] = NULL;
    va->img->coin[2] = NULL;
    va->img->down_pacman = NULL;
    va->img->enemy = NULL;
    va->img->exit = NULL;
    va->img->free_space = NULL;
    va->img->left_pacman = NULL;
    va->img->right_pacman = NULL;
    va->img->up_pacman = NULL;
    va->img->wall = NULL;
    va->img->left_wall = NULL;
    va->img->right_wall = NULL;
}
void implementation(char **map)
{
    t_vars va;
    int x;
    int y;

    va.mlx = mlx_init();
    if(!va.mlx)
        return ;
    init_to_null(&va);
    dimension(map, &x, &y);
    va.mlx_win = mlx_new_window(va.mlx, x * 64, y * 64, "PACMAN");
    if(!va.mlx_win)
        return ;
    va.map = map;
    render(&va, 0);
    mlx_hook(va.mlx_win, 2 ,1, key_hook, &va);
    mlx_loop_hook(va.mlx, lhook_ino, &va);
    mlx_hook(va.mlx_win, 17, 0, ft_quit, &va);
    mlx_loop(va.mlx);
}

int main(int ac, char **av)
{
    char **map;

    if (ac != 2 || check_param(av[1]) == 0)
        return (write(2, "Error\nincorrect parameter\n", 26),ft_malloc(-1), 1);
    if(check_file_and_map(av[1], &map) == 0)
        return (write(2, "Error\nincorrect map\n", 21),ft_malloc(-1), 1);
    if(check_file_and_map(av[1], &map) == 2)
        return (write(2, "Error\nincorrect file\n", 22),ft_malloc(-1), 1);
    implementation(map);
    return (ft_malloc(-1), 0);
}
