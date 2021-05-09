/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-malek.gatoufi
** File description:
** init_core_struct
*/

#include <stdlib.h>
#include "struct.h"
#include "init_core.h"
#include "my.h"

static status_t make_status_struct(void)
{
    status_t status;

    status.music = true;
    status.sfx = true;
    status.volume = 50;
    status.inviciblity = false;
    return (status);
}

static void init_map_limit(core_t *core)
{
    sfRectangleShape_setSize(core->hitbox.hitbox, (sfVector2f){40, 40});
    sfRectangleShape_setOutlineColor(core->hitbox.hitbox, sfBlue);
    core->hitbox.mapl = sfRectangleShape_copy(core->hitbox.hitbox);
    sfRectangleShape_setSize(core->hitbox.mapl, (sfVector2f){1150, 650});
    sfRectangleShape_setPosition(core->hitbox.mapl, (sfVector2f){400, 200});
    core->clock = sfClock_create();
    core->last_time = sfTime_Zero;
}

int init_core(core_t *core)
{
    char ***parsed = the_parser("config/init_core.conf");

    core->font = sfFont_createFromFile(parsed[0][1]);
    core->window = create_window((sfVideoMode) {my_getnbr(parsed[1][1]),
    my_getnbr(parsed[1][2]), my_getnbr(parsed[1][3])}, my_getnbr(parsed[2][1]),
    parsed[3][1], sfDefaultStyle);
    core->id_scene = parsed[4][1];
    parse_enemy("config/init_enemys.conf", core);
    create_scenes(core);
    create_map(core);
    create_minimap(core, "game");
    core->status = make_status_struct();
    core->buttonsfx = make_sound_effect("assets/musics/sound.ogg");
    core->deathsfx = make_sound_effect("assets/musics/death.ogg");
    core->translation.stop = false;
    create_player(core);
    spawn_tiles(core);
    init_map_limit(core);
    my_free("3", parsed);
    return (0);
}