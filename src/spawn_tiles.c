/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-malek.gatoufi
** File description:
** spawn_tiles
*/

#include <stdlib.h>
#include "struct.h"
#include "create_game_object.h"
#include "linked_list.h"
#include "create_map.h"

static void create_door(game_object_t **obj, sfVector2f position, float angle,
char *filepath)
{
    game_object_t *temp = NULL;

    temp = create_static_sprite((sfIntRect){0, 0, 50, 34}, filepath, position,
    (sfVector2f){4, 4});
    sfSprite_setOrigin(temp->sprite, (sfVector2f){50 / 2, 34 / 2});
    sfSprite_setRotation(temp->sprite, angle);
    put_at_end_list(obj, temp);
}

static void recenter_rooms(map_t **map)
{
    int current_x = 0;
    int current_y = 0;
    game_object_t *head;

    for (int y = 0; map[y]; ++y)
        for (int x = 0; map[y][x].type != -210; ++x)
            if (map[y][x].current) {
                current_x = x;
                current_y = y;
                break;
            }
    for (int y = 0; map[y]; ++y)
        for (int x = 0; map[y][x].type != -210; ++x) {
            head = map[y][x].obj;
            while (map[y][x].obj) {
                sfSprite_move(map[y][x].obj->sprite,
                (sfVector2f){-1920 * current_x, -1080 * current_y});
                map[y][x].obj = map[y][x].obj->next;
            }
            map[y][x].obj = head;
        }
}

static void spawn_objects(char **room, game_object_t *obj, int *roo,
core_t *core)
{
    game_object_t *temp;

    for (int y = 0; room[y]; ++y)
        for (int x = 0; room[y][x]; ++x)
            if (room[y][x] == '1') {
                put_at_end_list(&obj,
                create_static_sprite((sfIntRect){0, 0, 25, 27},
                "./assets/sprite/rock.png", OBJECTS(roo[0], roo[1], x, y),
                (sfVector2f){3.7, 3.7}));
            }
    for (int y = 0; room[y]; ++y)
        for (int x = 0; room[y][x]; ++x)
            if (room[y][x] == '3') {
                temp = create_enemy(&core->enemys[rand() % \
                (core->number_enemys - 1) + 1],
                OBJECTS(roo[0], roo[1], x, y));
                put_at_end_list(&obj, temp);
            }
}

static void condition(core_t *core, int x, int y)
{
    if (core->map[y][x].type != -1) {
        if (core->map[y][x].type != -1 && core->map[y][x].north)
            create_door(&core->map[y][x].obj, DOOR_N(x, y), 0,
            "./assets/sprite/door.png");
        if (core->map[y][x].type != -1 && core->map[y][x].south)
            create_door(&core->map[y][x].obj, DOOR_S(x, y), 180,
            "./assets/sprite/door.png");
        if (core->map[y][x].type != -1 && core->map[y][x].east)
            create_door(&core->map[y][x].obj, DOOR_E(x, y), 90,
            "./assets/sprite/door.png");
        if (core->map[y][x].type != -1 && core->map[y][x].west)
            create_door(&core->map[y][x].obj, DOOR_W(x, y), -90,
            "./assets/sprite/door.png");
        spawn_objects(core->map[y][x].room, core->map[y][x].obj,
        (int []){x, y}, core);
        if (core->map[y][x].last)
            put_at_end_list(&core->map[y][x].obj, create_enemy(&core->enemys[0],
            (sfVector2f){1920 * x + 1920 / 2, 1080 * y + 1080 / 2}));
    }
}

void spawn_tiles(core_t *core)
{
    for (int y = 0; core->map[y]; ++y)
        for (int x = 0; core->map[y][x].type != -210; ++x) {
            core->map[y][x].obj = NULL;
            if (core->map[y][x].type != -1)
                put_at_end_list(&core->map[y][x].obj,
                create_static_sprite((sfIntRect){0, 0, 1920, 1080},
                "./assets/sprite/room.png", ROOM(x, y), (sfVector2f){1, 1}));
            condition(core, x, y);
        }
    recenter_rooms(core->map);
}