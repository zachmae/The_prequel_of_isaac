/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** create_player
*/

#include "struct.h"
#include <stdlib.h>
#include "my.h"
#include "my_player.h"
#include "linked_list.h"

static void init_stats(core_t *core)
{
    core->stats[ATTACK] = 1;
    core->stats[SPEED] = 10;
    core->stats[LIFE] = 3;
    core->stats[LEVEL] = 1;
    core->stats[XP] = 0;
    core->stats[POINT] = 5;
    core->items[ATTACK] = 0;
    core->items[SPEED] = 0;
    core->items[LIFE] = 0;
}

static game_object_t *init_obj(char *config_line)
{
    game_object_t *obj = malloc(sizeof(game_object_t));
    char **arg = str_to_array(':', config_line);
    sfVector2f pos;
    sfVector2f sca;

    obj->type = PLAYER;
    obj->texture = sfTexture_createFromFile(arg[1], NULL);
    obj->sprite = sfSprite_create();
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    obj->rect = (sfIntRect){left: my_getnbr(arg[2]), top: my_getnbr(arg[3]), \
    height: my_getnbr(arg[5]), width: my_getnbr(arg[4])};
    obj->repitions = my_getnbr(arg[6]);
    obj->mov.x = (float)my_getnbr(arg[7]);
    obj->mov.y = (float)my_getnbr(arg[8]);
    pos.x = (float)my_getnbr(arg[9]);
    pos.y = (float)my_getnbr(arg[10]);
    sca.x = (float)my_getnbr(arg[11]) / 100;
    sca.y = (float)my_getnbr(arg[12]) / 100;
    init_objd(obj, arg, pos, sca);
    free_tab(arg);
    return (obj);
}

static void create_my_map_tmp(core_t *core)
{
    float x = 355;
    float y = 200;

    for (int i = 0; i < 7; i = i + 1) {
        core->hitbox.mapb[i] = malloc(sizeof(bool) * 13);
        core->hitbox.mapr[i] = malloc(sizeof(sfRectangleShape *) * 13);
        x = 355;
        for (int j = 0; j < 13; j += 1) {
            core->hitbox.mapb[i][j] = false;
            core->hitbox.mapr[i][j] = sfRectangleShape_copy(core->\
            hitbox.hitbox);
            sfRectangleShape_setPosition(core->hitbox.mapr[i][j], \
            (sfVector2f){x: x, y: y});
            x += 92.5;
        }
        y += 100;
    }
}

void create_my_map(core_t *core)
{
    sfRectangleShape_setOutlineThickness(core->hitbox.hitbox, 5);
    sfRectangleShape_setFillColor(core->hitbox.hitbox, sfTransparent);
    sfRectangleShape_setOutlineColor(core->hitbox.hitbox, sfRed);
    core->hitbox.mapb = malloc(sizeof(bool *) * 7);
    core->hitbox.mapr = malloc(sizeof(sfRectangleShape **) * 7);
    create_my_map_tmp(core);
}

void create_player(core_t *core)
{
    int c = find_scene("game", core);
    char **tab = str_to_array('\n', init_buffer("config/init_player.conf"));

    core->scene[c].player.larmes = NULL;
    core->scene[c].player.door = STAT;
    for (int i = 1; tab[i] != NULL; i = i + 1)
        put_at_end_list(&core->scene[c].objs, init_obj(tab[i]));
    for (; core->scene[c].name != NULL; c = c + 1)
        if (my_strcmp("tuto", core->scene[c].name) == 0)
            break;
    core->scene[c].player.larmes = NULL;
    for (int i = 1; tab[i] != NULL; i = i + 1)
        put_at_end_list(&core->scene[c].objs, init_obj(tab[i]));
    free_tab(tab);
    core->hitbox.hitbox = sfRectangleShape_create();
    sfRectangleShape_setSize(core->hitbox.hitbox, (sfVector2f){92.2, 92.5});
    create_my_map(core);
    init_stats(core);
    return;
}