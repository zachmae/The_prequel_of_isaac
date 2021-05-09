/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-malek.gatoufi
** File description:
** attack_ennemies
*/

#include "struct.h"
#include "coliding_system.h"
#include "my.h"

static game_object_t *get_objs(core_t *core)
{
    for (int y = 0; core->map[y]; ++y)
        for (int x = 0; core->map[y][x].type != -210; ++x)
            if (core->map[y][x].current)
                return (core->map[y][x].obj);
    return (NULL);
}

static void test(sfRectangleShape *rect, game_object_t *temp, lears_t *temp2,
    int attack)
{
    sfFloatRect rect2 = sfSprite_getGlobalBounds(temp->sprite);

    sfRectangleShape_setSize(rect, (sfVector2f){rect2.width, rect2.height});
    sfRectangleShape_setPosition(rect, (sfVector2f){rect2.left, rect2.top});
    if (coliding_system(C_R, rect, temp2->circle))
        temp->enemy.life -= attack;
}

void attack_ennemies(core_t *core)
{
    game_object_t *temp;
    lears_t *temp2;
    int count = 0;
    sfRectangleShape *rect = sfRectangleShape_create();

    if (my_strcmp(core->id_scene, "game") != 0)
        return;
    for (; my_strcmp(core->scene[count].name, "game"); ++count);
    temp2 = core->scene[count].player.larmes;
    for (; temp2; temp2 = temp2->next)
        for (temp = get_objs(core); temp; temp = temp->next)
            if (temp->type == ENEMIES)
                test(rect, temp, temp2, core->stats[ATTACK]);
    sfRectangleShape_destroy(rect);
}