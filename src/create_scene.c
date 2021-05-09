/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-malek.gatoufi
** File description:
** create_scene
*/

#include <stdlib.h>
#include "create_scene.h"
#include "struct.h"
#include "csfml.h"
#include "my.h"
#include "create_game_object.h"
#include "linked_list.h"

static char ***temp_2(scene_t *scene, char **buff)
{
    char ***buffer = the_parser(buff[2]);

    scene->objs = NULL;
    if (my_strcmp(buff[3], "null") == 0)
        scene->child = my_strdup("");
    else
        scene->child = my_strdup(buff[3]);
    scene->name = my_strdup(buff[0]);
    scene->music = sfMusic_createFromFile(buff[1]);
    return (buffer);
}

static void temp_3(char ***buffer, int i, game_object_t **tmp)
{
    if (my_strcmp(buffer[i][0], "GAME_BUTTONS") == 0)
        *tmp = create_game_buttons((sfIntRect){my_getnbr(buffer[i][1]),
        my_getnbr(buffer[i][2]), my_getnbr(buffer[i][3]),
        my_getnbr(buffer[i][4])}, buffer[i][11],
        (int []){my_getnbr(buffer[i][9]), my_getnbr(buffer[i][10])},
        (sfVector2f []){{my_getnbr(buffer[i][5]),
        my_getnbr(buffer[i][6])}, {(float) my_getnbr(buffer[i][7]) / 100,
        (float) my_getnbr(buffer[i][8]) / 100}});
}

static void temp_4(char ***buffer, int i, game_object_t **tmp)
{
    if (my_strcmp(buffer[i][0], "TEXT") == 0)
        *tmp = create_text((sfVector2f){my_getnbr(buffer[i][1]),
        my_getnbr(buffer[i][2])}, my_getnbr(buffer[i][3]), buffer[i][4]);
}

static void temp(scene_t *scene, char **buff, core_t *core)
{
    char ***buffer = temp_2(scene, buff);
    game_object_t *tmp;

    for (int i = 0; buffer[i]; ++i) {
        if (my_strcmp(buffer[i][0], "STATIC_SPRITE") == 0)
            tmp = create_static_sprite((sfIntRect){my_getnbr(buffer[i][1]),
            my_getnbr(buffer[i][2]), my_getnbr(buffer[i][3]),
            my_getnbr(buffer[i][4])}, buffer[i][9],
            (sfVector2f){my_getnbr(buffer[i][5]), my_getnbr(buffer[i][6])},
            (sfVector2f){(float) my_getnbr(buffer[i][7]) / 100,
            (float) my_getnbr(buffer[i][8]) / 100});
        temp_3(buffer, i, &tmp);
        temp_4(buffer, i, &tmp);
        put_at_end_list(&scene->objs, tmp);
        if (my_strcmp(core->id_scene, "menu") == 0)
            make_particles_mov(&scene->objs);
    }
    my_free("3", buffer);
}

void create_scenes(core_t *core)
{
    char ***buff = the_parser("config/init_scenes.conf");
    core->scene = malloc(sizeof(scene_t) * (my_tablen(buff) + 1));

    for (int i = 0; buff[i]; ++i)
        temp(&core->scene[i], buff[i], core);
    core->scene[my_tablen(buff)].name = NULL;
    core->id_scene = "start";
    my_free("3", buff);
}