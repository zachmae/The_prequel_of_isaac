/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** init_objd
*/

#include "struct.h"
#include <stdlib.h>
#include "my.h"
#include "my_player.h"
#include "linked_list.h"

static const void *update_player[] = {
    &upt_head,
    &upt_body,
    NULL
};

void init_objd(game_object_t *obj, char **arg, sfVector2f pos, sfVector2f sca)
{
    obj->mov_delay = my_getnbr(arg[13]);
    obj->an_delay = my_getnbr(arg[14]);
    obj->an_time.microseconds = 0;
    obj->mov_time.microseconds = 0;
    obj->text = NULL;
    obj->update = update_player[my_getnbr(arg[17])];
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    sfSprite_setPosition(obj->sprite, pos);
    sfSprite_setScale(obj->sprite, sca);
    sca.x = obj->rect.width / 2;
    sca.y = obj->rect.height / 2;
    sfSprite_setOrigin(obj->sprite, sca);
    obj->next = NULL;
}
