/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** creatre_enemy
*/

#include <stdlib.h>
#include "struct.h"
#include "enemie.h"
#include "create_scene.h"
#include "my.h"

void parse_enemy(char *conf, core_t *core)
{
    char ***enemy_conf = the_parser(conf);

    core->number_enemys = my_tablen(enemy_conf);
    core->enemys = malloc(sizeof(init_enemy_t) * (my_tablen(enemy_conf) + 1));
    for (int i = 0; enemy_conf[i] != NULL; ++i) {
        core->enemys[i].filepath = my_strdup(enemy_conf[i][0]);
        core->enemys[i].rect = (sfIntRect){
            my_getnbr(enemy_conf[i][1]),
            my_getnbr(enemy_conf[i][2]),
            my_getnbr(enemy_conf[i][3]),
            my_getnbr(enemy_conf[i][4])};
        core->enemys[i].an_delay = my_getnbr(enemy_conf[i][5]);
        core->enemys[i].mov_delay = my_getnbr(enemy_conf[i][6]);
        core->enemys[i].repetition = my_getnbr(enemy_conf[i][7]);
        core->enemys[i].scale = (sfVector2f){my_getnbr(enemy_conf[i][8]),
        my_getnbr(enemy_conf[i][9])};
        core->enemys[i].life = my_getnbr(enemy_conf[i][10]);
        core->enemys[i].damage = my_getnbr(enemy_conf[i][11]);
        core->enemys[i].speed = (float)my_getnbr(enemy_conf[i][12])
        / (float)my_getnbr(enemy_conf[i][13]);
    }
}

static void assign_values_enemy(game_object_t *obj)
{
    obj->an_time = sfTime_Zero;
    obj->mov_time = sfTime_Zero;
    obj->type = ENEMIES;
    obj->next = NULL;
}

game_object_t *create_enemy(init_enemy_t *enemy, sfVector2f position)
{
    game_object_t *obj = malloc(sizeof(game_object_t));

    assign_values_enemy(obj);
    obj->rect = enemy->rect;
    obj->texture = sfTexture_createFromFile(enemy->filepath, NULL);
    obj->sprite = sfSprite_create();
    sfSprite_setTexture(obj->sprite, obj->texture, false);
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    sfSprite_setScale(obj->sprite, enemy->scale);
    obj->an_delay = enemy->an_delay;
    obj->mov_delay = enemy->mov_delay;
    obj->repitions = enemy->repetition;
    obj->update = update_enemy;
    obj->enemy.life = enemy->life;
    obj->enemy.damage = enemy->damage;
    obj->enemy.speed = enemy->speed;
    sfSprite_setPosition(obj->sprite, position);
    sfSprite_setOrigin(obj->sprite,
    (sfVector2f){obj->rect.width / 2, obj->rect.height / 2});
    return obj;
}