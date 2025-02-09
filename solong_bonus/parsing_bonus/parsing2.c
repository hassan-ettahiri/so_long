#include "../so_long_bonus.h"

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
