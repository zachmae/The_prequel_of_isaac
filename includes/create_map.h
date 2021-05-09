/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-malek.gatoufi
** File description:
** create_map
*/

#ifndef CREATE_MAP_H_
#define CREATE_MAP_H_

#include <stdbool.h>

#define DOOR_N(x, y) ((sfVector2f){1920 / 2 + 1920 * x, 130 + 1080 * y})
#define DOOR_S(x, y) ((sfVector2f){1920 / 2 + 1920 * x, 1080 - 120 + 1080 * y})
#define DOOR_E(x, y) ((sfVector2f){1920 - 280 + 1920 * x, 1080 / 2 + 1080 * y})
#define DOOR_W(x, y) ((sfVector2f){280 + 1920 * x, 1080 / 2 + 1080 * y})
#define ROOM(x, y) ((sfVector2f){1920 * x, 1080 * y})
#define OBJECTS(x_room, y_room, x, y) \
((sfVector2f){1920 * x_room + x * 92.5 + 355, 1080 * y_room + y * 99.9 + 200})

void assign_array(map_t **map, char ***buff);
bool check_map(map_t **map, int nb);
void change_cur_map(int *p, map_t *cur_map, int *count, int *length);
void test(map_t **map, char *directions, int *count, ...);
map_t **resize_map(map_t **map);
char ***the_parser(char *filepath);

#endif /* !CREATE_MAP_H_ */