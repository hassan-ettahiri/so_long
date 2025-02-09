#include "../so_long_bonus.h"

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