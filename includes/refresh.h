/*
** EPITECH PROJECT, 2021
** my rpg
** File description:
** refresh.h
*/

#ifndef REFRESH_H_
#define REFRESH_H_

#include "struct.h"

void attack_ennemies(core_t *core);
void display_map(core_t *core);
void display_scene(char *id_scene, scene_t *scene, sfRenderWindow *win);
void music_start(scene_t *scene, char *scene_id, bool status, float volume);
void music_stop(scene_t *scene, char *scene_id, bool status);
void refresh_cinematic(core_t *core);
void change_room(map_t **map, char direction);
void refresh_text(core_t *core);
void update_room(core_t *core);
void moove_objects(map_t **map, core_t *core);
void refresh_particles(core_t *core);

#endif /* !REFRESH_H_ */