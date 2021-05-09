/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-malek.gatoufi
** File description:
** create_map2
*/

#include <stdlib.h>
#include "struct.h"
#include "create_map.h"
#include "my.h"

bool check_map(map_t **map, int nb)
{
    int count = 0;

    for (int y = 0; map[y]; ++y)
        for (int x = 0; map[y][x].type != -210; ++x)
            if (map[y][x].type != -1)
                count++;
    if (count == nb)
        return (true);
    return (false);
}

static void compute_values(map_t **map, int *values)
{
    for (int y = 0; map[y]; ++y)
        for (int x = 0; map[y][x].type != -210; ++x) {
            if (map[y][x].type != -1 && x < values[0])
                values[0] = x;
            if (map[y][x].type != -1 && y < values[1])
                values[1] = y;
            if (map[y][x].type != -1 && x > values[2])
                values[2] = x;
            if (map[y][x].type != -1 && y > values[3])
                values[3] = y;
        }
    values[3]++;
    values[2]++;
}

void assign_array(map_t **map, char ***buff)
{
    int nb = 0;

    for (int y = 0; map[y]; ++y)
        for (int x = 0; map[y][x].type != -210; ++x) {
            if (map[y][x].type != -1 && !map[y][x].last) {
                nb = (rand() % (tablen(buff) - 2)) + 2;
                map[y][x].room = my_tabdup(buff[nb]);
            }
            if (map[y][x].type != -1 && map[y][x].last)
                map[y][x].room = my_tabdup(buff[1]);
            nb = 0;
        }
}

void change_cur_map(int *p, map_t *cur_map, int *count, int *length)
{
    if (length[0] == 1)
        cur_map->last = true;
    !cur_map->north ? cur_map->north = p[0] : 0;
    !cur_map->south ? cur_map->south = p[1]: 0;
    !cur_map->east ? cur_map->east = p[2]: 0;
    !cur_map->west ? cur_map->west = p[3]: 0;
    cur_map->type = 1;
    count[0] += 1;
}

map_t **resize_map(map_t **map)
{
    int values[] = {1000, 1000, 0, 0};
    map_t **dup_map;

    compute_values(map, values);
    dup_map = malloc(sizeof(map_t *) * ((values[3] - values[1]) + 1));
    dup_map[values[3] - values[1]] = NULL;
    for (int i = 0; i < (values[3] - values[1]); ++i) {
        dup_map[i] = malloc(sizeof(map_t) * ((values[2] - values[0]) + 1));
        dup_map[i][values[2] - values[0]].type = -210;
        for (int x = 0; x < (values[2] - values[0]); ++x) {
            dup_map[i][x].type = map[values[1] + i][values[0] + x].type;
            dup_map[i][x].current = map[values[1] + i][values[0] + x].current;
            dup_map[i][x].south = map[values[1] + i][values[0] + x].south;
            dup_map[i][x].north = map[values[1] + i][values[0] + x].north;
            dup_map[i][x].west = map[values[1] + i][values[0] + x].west;
            dup_map[i][x].east = map[values[1] + i][values[0] + x].east;
            dup_map[i][x].last = map[values[1] + i][values[0] + x].last;
        }
    }
    my_free("2", map);
    return (dup_map);
}