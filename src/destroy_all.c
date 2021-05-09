/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-malek.gatoufi
** File description:
** init_core_struct
*/

#include <stdlib.h>
#include "struct.h"
#include "my.h"
#include "destroy.h"

static void destroy_obj_parse(game_object_t *tmp)
{
    switch (tmp->type) {
        case MINIMAP:
            destroy_minimap(tmp);
            break;
        case TEXT:
            destroy_text(tmp);
            break;
        case PARTICLE:
            sfCircleShape_destroy(tmp->particle.circle);
            break;
        default:
            sfSprite_destroy(tmp->sprite);
            sfTexture_destroy(tmp->texture);
            break;
    }
}

static void destroy_obj_tmp(game_object_t **list)
{
    switch ((*list)->type) {
        case MINIMAP:
            destroy_minimap((*list));
            break;
        case TEXT:
            destroy_text((*list));
            break;
        case PARTICLE:
            sfCircleShape_destroy((*list)->particle.circle);
            break;
        default:
            sfSprite_destroy((*list)->sprite);
            sfTexture_destroy((*list)->texture);
            break;
    }
}

static void destroy_obj(game_object_t **list)
{
    game_object_t *tmp = (*list)->next;
    game_object_t *next = (*list)->next;

    while (next != NULL) {
        tmp = next;
        next = next->next;
        destroy_obj_parse(tmp);
        free(tmp);
    }
    destroy_obj_tmp(list);
    free(*list);
}

static void destroy_scenes(scene_t *scene)
{
    for (int i = 0; scene[i].name; i++) {
        free(scene[i].name);
        free(scene[i].child);
        sfMusic_destroy(scene[i].music);
        destroy_obj(&scene[i].objs);
    }
    return;
}

void destroy_all(core_t *core)
{
    sfClock_destroy(core->clock);
    sfFont_destroy(core->font);
    destroy_scenes(core->scene);
    destroy_map(core->map);
    sfRenderWindow_destroy(core->window);
    sfSoundBuffer_destroy(core->buttonsfx->buffer);
    sfSound_destroy(core->buttonsfx->sound);
    sfSoundBuffer_destroy(core->deathsfx->buffer);
    sfSound_destroy(core->deathsfx->sound);
    return;
}