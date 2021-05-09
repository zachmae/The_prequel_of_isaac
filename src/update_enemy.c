/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** update_enemy
*/

#include "struct.h"
#include "update_animated_object.h"
#include "enemie.h"
#include "my.h"
#include <stdlib.h>

static void is_current_room(map_t **map, int *y, int *x)
{
    for (int i = 0; map[i]; ++i) {
        for (int j = 0; map[i][j].type != -210; ++j) {
            if (map[i][j].current) {
                *y = i;
                *x = j;
                return;
            }
        }
    }
}

static game_object_t *get_current_room(core_t *core)
{
    for (int y = 0; core->map[y]; ++y)
        for (int x = 0; core->map[y][x].type != -210; ++x)
            if (core->map[y][x].current)
                return (core->map[y][x].obj);
    return (NULL);
}

static void ping_life(game_object_t *obj, core_t *core)
{
    game_object_t *head = NULL;
    game_object_t *prev = NULL;
    game_object_t *temp = NULL;

    if (obj->enemy.life > 0)
        return;
    level_handle(core->stats);
    head = get_current_room(core);
    temp = head;
    while (temp && temp != obj) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    core->items[rand() % 3]++;
}

void update_enemy(core_t *core, game_object_t *obj)
{
    int x = 0;
    int y = 0;

    if (my_strcmp(core->id_scene, "game") == 0) {
        update_animated_an(core, obj);
        is_current_room(core->map, &y, &x);
        path_finding(obj, true, core);
        update_animated_move(core, obj);
        ping_life(obj, core);
    }
}