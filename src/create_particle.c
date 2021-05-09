/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** create_particle
*/

#include "struct.h"
#include "update_animated_object.h"
#include "linked_list.h"
#include <stdlib.h>
#include <stdarg.h>

static void update_move_particle(core_t *core, game_object_t *obj)
{
    sfTime mov_time = sfClock_getElapsedTime(core->clock);
    sfInt32 time = sfTime_asMilliseconds(obj->mov_time);
    sfInt32 time2 = sfTime_asMilliseconds(mov_time);

    if (time2 - time >= obj->mov_delay) {
        sfCircleShape_move(obj->particle.circle, obj->mov);
        obj->mov_time = mov_time;
    }
}

static void update_particle(core_t *core, game_object_t *obj)
{
    update_move_particle(core, obj);
}

void display_particles(game_object_t *obj, sfRenderWindow *window)
{
    sfRenderWindow_drawCircleShape(window, obj->particle.circle, NULL);
}

static void set_particles(game_object_t *obj)
{
    sfCircleShape_setPosition(obj->particle.circle, obj->pos);
    sfCircleShape_setRadius(obj->particle.circle, obj->particle.radius);
    sfCircleShape_setFillColor(obj->particle.circle, obj->particle.color);
}

game_object_t *create_particle(sfVector2f pos, int count, ...)
{
    game_object_t *obj = malloc(sizeof(game_object_t));
    va_list ap;

    va_start(ap, count);
    obj->type = PARTICLE;
    obj->pos = pos;
    obj->particle.color = va_arg(ap, sfColor);
    obj->particle.speed = (float)va_arg(ap, double);
    obj->particle.time = va_arg(ap, sfInt32);
    obj->mov_delay = va_arg(ap, sfInt32);
    obj->particle.radius = (float)va_arg(ap, double);
    obj->particle.circle = sfCircleShape_create();
    set_particles(obj);
    obj->particle.size = va_arg(ap, int);
    obj->update = update_particle;
    obj->an_time = sfTime_Zero;
    obj->mov_time = sfTime_Zero;
    obj->next = NULL;
    va_end(ap);
    return obj;
}
