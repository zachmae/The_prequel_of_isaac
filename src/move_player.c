/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** move_player
*/

#include "my_player.h"
#include "my.h"
#include "struct.h"

void move_char(core_t *core)
{
    int i = 0;
    int j = 0;

    for (int si = 0; core->map[si] != NULL; si = si + 1)
        for (int sj = 0; core->map[si][sj].type != -210; sj = sj + 1)
            if (core->map[si][sj].current == true) {
                j = sj;
                i = si;
            }
    for (int a = 0; a < 7; a += 1)
        for (int b = 0; b < 13; b += 1)
            if (core->map[i][j].room[a][b] == '1')
                core->hitbox.mapb[a][b] = true;
            else
                core->hitbox.mapb[a][b] = false;
}

void check_door(core_t *core, int c, sfVector2f pos)
{
    core->scene[c].player.door = STAT;
    if (pos.y <= 200) {
        if (pos.x > 900 && pos.x < 950)
            core->scene[c].player.door = UP;
    }
    if (pos.y >= 840) {
        if (pos.x > 900 && pos.x < 950)
            core->scene[c].player.door = DOW;
    }
    if (pos.x <= 400) {
        if (pos.y > 500 && pos.y < 550)
            core->scene[c].player.door = LEFT;
    }
    if (pos.x >= 1510) {
        if (pos.y > 500 && pos.y < 550)
            core->scene[c].player.door = RIGH;
    }
}

sfBool check_colision(core_t *core, sfVector2f pos, int c)
{
    sfFloatRect hitbox = sfRectangleShape_getGlobalBounds(core->hitbox.hitbox);
    sfFloatRect tamp;

    if (my_strcmp(core->id_scene, "tuto") == 0)
        return (sfTrue);
    hitbox.top += pos.y;
    hitbox.left += pos.x;
    for (int i = 0; i < 7; i += 1)
        for (int j = 0; j < 13; j += 1)
            if (core->hitbox.mapb[i][j] == true) {
                tamp = sfRectangleShape_getGlobalBounds(\
                core->hitbox.mapr[i][j]);
                if (sfFloatRect_intersects(&hitbox, &tamp, NULL) == sfTrue)
                    return (sfFalse);
            }
    tamp = sfRectangleShape_getGlobalBounds(core->hitbox.mapl);
    if (sfFloatRect_intersects(&hitbox, &tamp, NULL) == sfTrue) {
        check_door(core, c, (sfVector2f){hitbox.left, hitbox.top});
        return (sfTrue);
    }
    return (sfFalse);
}

void move_player_two(core_t *core, int c, sfVector2f *pos, sfVector2f *pos2)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue && check_colision\
    (core, (sfVector2f){-core->stats[SPEED], 0}, c) == sfTrue) {
        pos->x -= core->stats[SPEED];
        pos2->x -= core->stats[SPEED];
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue && check_colision(core\
    , (sfVector2f){core->stats[SPEED], 0}, c) == sfTrue) {
        pos->x += core->stats[SPEED];
        pos2->x += core->stats[SPEED];
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue && check_colision\
    (core, (sfVector2f){0, -core->stats[SPEED]}, c) == sfTrue) {
        pos2->y -= core->stats[SPEED];
        pos->y -= core->stats[SPEED];
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue && check_colision(core\
    , (sfVector2f){0, core->stats[SPEED]}, c) == sfTrue) {
        pos->y += core->stats[SPEED];
        pos2->y += core->stats[SPEED];
    }
}

void move_player(game_object_t *obj, core_t *core)
{
    int c = find_scene("game", core);
    sfVector2f pos = sfSprite_getPosition(obj->sprite);
    sfVector2f pos2 = sfSprite_getPosition(obj->next->sprite);

    core->scene[c].player.door = STAT;
    move_char(core);
    move_player_two(core, c, &pos, &pos2);
    check_door_two(core, c, pos);
    sfSprite_setPosition(obj->sprite, pos);
    sfSprite_setPosition(obj->next->sprite, pos2);
    sfRectangleShape_setPosition(core->hitbox.hitbox, \
    (sfVector2f){(pos.x - 10), (pos.y - 15)});
}