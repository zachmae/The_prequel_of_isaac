/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-malek.gatoufi
** File description:
** create_map
*/

#include <stdarg.h>
#include <stdlib.h>
#include "struct.h"
#include "create_map.h"
#include "my.h"

static void init_start_map(map_t **map, int length)
{
    int x = 0;

    for (int i = 0; i < length; ++i) {
        for (x = 0; x < length; ++x) {
            map[i][x].type = -1;
            map[i][x].east = false;
            map[i][x].west = false;
            map[i][x].south = false;
            map[i][x].north = false;
            map[i][x].current = false;
            map[i][x].last = false;
        }
        map[i][x].type = -210;
    }
    map[length / 2][length / 2].type = 0;
    map[length / 2][length / 2].current = true;
    map[length / 2][length / 2].north = false;
    map[length / 2][length / 2].south = false;
    map[length / 2][length / 2].east = false;
    map[length / 2][length / 2].west = false;
}

static void rand_directions(char *directions)
{
    int rand1 = 0;
    int rand2 = 0;
    char temp;

    for (int i = 0; directions[i]; ++i) {
        rand1 = rand() % 4;
        rand2 = rand() % 4;
        temp = directions[rand1];
        directions[rand1] = directions[rand2];
        directions[rand2] = temp;
    }
}

static void add_rooms(map_t **map, int y, int x, int *length)
{
    char directions[] = "NSEW";
    int count = 0;

    rand_directions(directions);
    length[0]--;
    for (int i = 0; directions[i]; ++i) {
        test(map, directions, &count, length, (int []){i, x, y, 'N', 1, 0},
        (int []){true, false, false, false, false, true, false, false});
        test(map, directions, &count, length, (int []){i, x, y, 'S', -1, 0},
        (int []){false, true, false, false, true, false, false, false});
        test(map, directions, &count, length, (int []){i, x, y, 'E', 0, 1},
        (int []){false, false, false, true, false, false, true, false});
        test(map, directions, &count, length, (int []){i, x, y, 'W', 0, -1},
        (int []){false, false, true, false, false, false, false, true});
    }
}

void test(map_t **map, char *directions, int *count, ...)
{
    va_list ap;
    int *length;
    int *v;
    int *p;
    map_t *cur_map;

    va_start(ap, count);
    length = va_arg(ap, int *);
    v = va_arg(ap, int *);
    p = va_arg(ap, int *);
    cur_map = &map[v[2] + v[4]][v[1] + v[5]];
    va_end(ap);
    if (directions[v[0]] == v[3] && (rand() % 2 || (v[0] == 3 && *count == 0))
        && cur_map->type == -1 && length[0] != 0) {
        change_cur_map(p, cur_map, count, length);
        !map[v[2]][v[1]].north ? map[v[2]][v[1]].north = p[4]: 0;
        !map[v[2]][v[1]].south ? map[v[2]][v[1]].south = p[5]: 0;
        !map[v[2]][v[1]].east ? map[v[2]][v[1]].east = p[6]: 0;
        !map[v[2]][v[1]].west ? map[v[2]][v[1]].west = p[7]: 0;
        add_rooms(map, v[2] + v[4], v[1] + v[5], length);
    }
}

void create_map(core_t *core)
{
    char ***buff = the_parser("./config/init_map.conf");
    int maze_len = my_getnbr(buff[0][0]);
    map_t **map = malloc(sizeof(map_t *) * (maze_len * 2 + 1));
    map_t **dup_map = NULL;
    int length[] = {maze_len};

    for (int i = 0; i < maze_len * 2 + 1; ++i)
        map[i] = malloc(sizeof(map_t) * (maze_len * 2 + 1));
    init_start_map(map, maze_len * 2);
    add_rooms(map, maze_len, maze_len, length);
    map[maze_len * 2] = NULL;
    dup_map = resize_map(map);
    assign_array(dup_map, buff);
    if (!check_map(dup_map, my_getnbr(buff[0][0]))) {
        create_map(core);
        return;
    }
    my_free("3", buff);
    core->map = dup_map;
}