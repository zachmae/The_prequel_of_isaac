/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** update_player
*/

#include "struct.h"
#include "my_player.h"

static sfIntRect key_handling(sfIntRect rect)
{
    rect.left = (rect.left);
    if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue \
    && sfKeyboard_isKeyPressed(sfKeyZ) == sfFalse)
        rect.left = (rect.left + 240);
    else if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue)
        rect.left = (rect.left + 80);
    else if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue && \
    sfKeyboard_isKeyPressed(sfKeyQ) == sfFalse)
        rect.left = (rect.left + 160);
    return (rect);
}

void update_skin(game_object_t *obj, sfKeyCode right, sfKeyCode left)
{
    if (sfKeyboard_isKeyPressed(right) == sfTrue && obj->mov_delay < 1695) {
        obj->mov_delay += 339;
        obj->rect.left += 339;
    }
    if (sfKeyboard_isKeyPressed(left) == sfTrue && obj->mov_delay > 0) {
        obj->mov_delay -= 339;
        obj->rect.left -= 339;
    }
}

void upt_head(core_t *core, game_object_t *obj)
{
    int c = find_scene("game", core);
    obj->mov_time = sfClock_getElapsedTime(core->clock);
    core->scene[c].player.mov_fire = sfClock_getElapsedTime(core->clock);
    float second = (float)(((float)obj->mov_time.microseconds - \
    (float)obj->an_time.microseconds) / (float)1000000);
    sfIntRect rect = key_handling(obj->rect);
    update_skin(obj, sfKeyM, sfKeyL);
    if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue || sfKeyboard_isKeyPressed\
    (sfKeyD) == sfTrue || sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue || \
    sfKeyboard_isKeyPressed(sfKeyS) == sfTrue) {
        if (second > 0.00 && second <= 0.25) {
            rect.left += 40;
            if (second > 0.00 && second <= 0.02)
                add_lears(core, obj, c);
        } else if (second >= 0.5) {
                core->scene[c].player.an_fire.microseconds = \
                core->scene[c].player.mov_fire.microseconds;
            obj->an_time.microseconds = obj->mov_time.microseconds;
        }
    }
    sfSprite_setTextureRect(obj->sprite, rect);
}

int rect_body(game_object_t *obj, core_t *core)
{
    move_player(obj, core);
    update_skin(obj, sfKeyP, sfKeyO);
    obj->an_time.microseconds = obj->mov_time.microseconds;
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
        obj->rect.top = 157;
        obj->rect.left -= 32;
        if ((obj->rect.left - obj->mov_delay + 5) < 0)
            obj->rect.left = obj->mov_delay + 5 + 288;
        return (1);
    } else if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
        obj->rect.top = 112;
        obj->rect.left += 32;
        if ((obj->rect.left - obj->mov_delay + 5) > 320)
            obj->rect.left = obj->mov_delay + 5;
        return (1);
    }
    return (0);
}

void upt_body(core_t *core, game_object_t *obj)
{
    obj->mov_time = sfClock_getElapsedTime(core->clock);
    if ((float)(((float)obj->mov_time.microseconds - \
    (float)obj->an_time.microseconds) / (float)1000000) >= 0.02) {
        if (rect_body(obj, core) == 1)
            ;
        else if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
            obj->rect.top = 70;
            obj->rect.left += 32;
            if ((obj->rect.left - obj->mov_delay + 5) > 320)
                obj->rect.left = obj->mov_delay + 5;
        } else if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
            obj->rect.top = 70;
            obj->rect.left -= 32;
            if ((obj->rect.left - obj->mov_delay + 5) < 0)
                obj->rect.left = obj->mov_delay + 5 + 288;
        } else {
            obj->rect.left = (obj->mov_delay + 5);
            obj->rect.top = 70;
        }
    }
    sfSprite_setTextureRect(obj->sprite, obj->rect);
}
