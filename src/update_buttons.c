/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-malek.gatoufi
** File description:
** handle_buttons
*/

#include "struct.h"

static void click_condition(game_object_t *objs)
{
    if (objs->repitions == 3 && !objs->game_buttons.clicked) {
        objs->rect.left = objs->rect.width * 2;
        objs->game_buttons.clicked = true;
    } else if (objs->repitions == 3 && objs->game_buttons.clicked) {
        objs->rect.left = 0;
        objs->game_buttons.clicked = false;
    }
}

void update_buttons(core_t *core, game_object_t *objs)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(core->window);
    sfFloatRect size = sfSprite_getGlobalBounds(objs->sprite);

    if (sfFloatRect_contains(&size, (float)mouse.x,
    (float)mouse.y) == sfTrue) {
        if (core->status.click == true) {
            if (core->status.sfx == true)
                sfSound_play(core->buttonsfx->sound);
            core->status.click = false;
            click_condition(objs);
            objs->game_buttons.callback(core);
        } else if (!objs->game_buttons.clicked)
            objs->rect.left = objs->rect.width * 1;
    } else if (!objs->game_buttons.clicked)
        objs->rect.left = 0;
    sfSprite_setTextureRect(objs->sprite, objs->rect);
}
