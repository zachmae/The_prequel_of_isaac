/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** init_core
*/

#ifndef INIT_CORE_H_
#define INIT_CORE_H_

#include "csfml.h"

void init_inventory(core_t *core);
void spawn_tiles(core_t *core);
void create_minimap(core_t *core, char *s);
void create_map(core_t *core);
void create_scenes(core_t *core);
char ***the_parser(char *filepath);
sfRenderWindow *create_window(sfVideoMode mode, int limit,
char const *title, sfUint32 style);
void create_player(core_t *core);
void music_start(scene_t *scene, char *scene_id, bool status, float volume);
sound_t *make_sound_effect(char *path);
void create_player(core_t *core);
void parse_enemy(char *conf, core_t *core);

#endif /* !INIT_CORE_H_ */