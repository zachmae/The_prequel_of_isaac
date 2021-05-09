/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** mov_particle
*/

#include "struct.h"
#include "linked_list.h"
#include "create_game_object.h"
#include "my.h"
#include <stdlib.h>

void refresh_particles(core_t *core)
{
    sfTime time = sfClock_getElapsedTime(core->clock);
    sfInt32 old_time = sfTime_asMilliseconds(time);
    sfInt32 new_time = sfTime_asMilliseconds(core->last_time);

    if (old_time - new_time >= 1000) {
        make_particles_mov(&core->scene->objs);
        core->last_time = time;
    }
}

void make_particles_mov(game_object_t **objs)
{
    game_object_t *obj_temp = malloc(sizeof(game_object_t));

    for (int i = 0; i < 100; ++i) {
        obj_temp = create_particle((sfVector2f) {10, 10}, 6,
        sfRed, 0.20, 10, 10, 10.0, 1950);
        obj_temp->pos.y = -20;
        obj_temp->pos.x = rand() % obj_temp->particle.size;
        obj_temp->mov.x = 0;
        obj_temp->mov.y = 0;
        if (rand() % 1000 < 200) {
            obj_temp->mov.y = rand () % 10 * obj_temp->particle.speed;
            sfCircleShape_setPosition(obj_temp->particle.circle,
            obj_temp->pos);
            sfCircleShape_move(obj_temp->particle.circle, obj_temp->mov);
            put_at_end_list(objs, obj_temp);
        } else
            sfCircleShape_destroy(obj_temp->particle.circle);
    }
}