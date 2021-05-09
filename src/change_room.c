/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-malek.gatoufi
** File description:
** change_room
*/

#include "my.h"
#include "struct.h"
#include "change_room.h"

static void change_pos(char direction, sfVector2f *pos, sfVector2f *pos2)
{
    switch (direction) {
        case 'S':
            *pos = (sfVector2f){pos->x, 220};
            *pos2 = (sfVector2f){pos2->x, 152};
            break;
        case 'N':
            *pos = (sfVector2f){pos->x, 825};
            *pos2 = (sfVector2f){pos2->x, 757};
            break;
        case 'E':
            *pos = (sfVector2f){440, pos->y};
            *pos2 = (sfVector2f){462, pos2->y};
            break;
        case 'W':
            *pos = (sfVector2f){1460, pos->y};
            *pos2 = (sfVector2f){1482, pos2->y};
    }
}

static void moove_playe(game_object_t *obj, char direction)
{
    sfVector2f pos = sfSprite_getPosition(obj->sprite);
    sfVector2f pos2 = sfSprite_getPosition(obj->next->sprite);

    change_pos(direction, &pos, &pos2);
    sfSprite_setPosition(obj->sprite, pos);
    sfSprite_setPosition(obj->next->sprite, pos2);
}

static void change_current(map_t **map, int y_offset, int x_offset,
core_t *core)
{
    for (int y = 0; map[y]; ++y)
        for (int x = 0; map[y][x].type != -210; ++x)
            if (map[y][x].current) {
                map[y][x].current = false;
                map[y + y_offset][x + x_offset].current = true;
                core->translation.stop = true;
                core->translation.last_time = \
                sfTime_asMicroseconds(sfClock_getElapsedTime(core->clock));
                core->translation.delay = 16666;
                core->translation.repitions = 60;
                core->translation.movement = \
                (sfVector2f){-32 * x_offset, -18 * y_offset};
                return;
            }
}

static void change_room(map_t **map, char direction, game_object_t *obj,
core_t *core)
{
    if (direction == 'N')
        change_current(map, -1, 0, core);
    if (direction == 'S')
        change_current(map, 1, 0, core);
    if (direction == 'E')
        change_current(map, 0, 1, core);
    if (direction == 'W')
        change_current(map, 0, -1, core);
    moove_playe(obj, direction);
}

void update_room(core_t *core)
{
    game_object_t *temp = NULL;
    int count = 0;

    if (my_strcmp(core->id_scene, "game") != 0)
        return;
    get_player(&temp, core, &count);
    for (int y = 0; core->map[y]; ++y)
        for (int x = 0; core->map[y][x].type != -210; ++x) {
            if (core->map[y][x].type == -1 || !core->map[y][x].current)
                continue;
            if (core->map[y][x].north && core->scene[count].player.door == UP)
                change_room(core->map, 'N', temp, core);
            if (core->map[y][x].south && core->scene[count].player.door == DOW)
                change_room(core->map, 'S', temp, core);
            if (core->map[y][x].east && core->scene[count].player.door == RIGH)
                change_room(core->map, 'E', temp, core);
            if (core->map[y][x].west
                && core->scene[count].player.door == LEFT)
                change_room(core->map, 'W', temp, core);
            return;
        }
}