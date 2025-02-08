#include "../../so_long.h"

int all_coin_collected(char **map)
{
    int i = 0;
    int j = 0;

    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
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
    if(map[y - 1][x] == '0' || map[y - 1][x] == 'C')
    {
        map[y][x] = '0';
        map[y - 1][x] = 'P';
        render(va, 1);
    }
    if(map[y - 1][x] == 'E')
    {
        if(all_coin_collected(map) == 1)
            exit_game(va, 1);
    }
}

void move_down(t_vars *va)
{
    char **map;
    int x;
    int y;

    map = va->map;
    find_player(map, &x, &y);
    if(map[y + 1][x] == '0' || map[y + 1][x] == 'C')
    {
        map[y][x] = '0';
        map[y + 1][x] = 'P';
        render(va, 2);
    }
    if(map[y + 1][x] == 'E')
    {
        if(all_coin_collected(map) == 1)
            exit_game(va, 1);
    }
}

void move_left(t_vars *va)
{
    char **map;
    int x;
    int y;

    map = va->map;
    find_player(map, &x, &y);
    if(map[y][x - 1] == '0' || map[y][x - 1] == 'C')
    {
        map[y][x] = '0';
        map[y][x - 1] = 'P';
        render(va, 3);
    }
    if(map[y][x - 1] == 'E')
    {
        if(all_coin_collected(map) == 1)
            exit_game(va, 1);
    }
}

void move_right(t_vars *va)
{
    char **map;
    int x;
    int y;

    map = va->map;
    find_player(map, &x, &y);
    if(map[y][x + 1] == '0' || map[y][x + 1] == 'C')
    {
        map[y][x] = '0';
        map[y][x + 1] = 'P';
        render(va, 4);
    }
    if(map[y][x + 1] == 'E')
    {
        if(all_coin_collected(map) == 1)
            exit_game(va, 1);
    }
}
