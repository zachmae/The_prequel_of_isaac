/*
** EPITECH PROJECT, 2021
** my rpg
** File description:
** rpg.h
*/

#ifndef MY_RPG_H_
#define MY_RPG_H_

#include "struct.h"

int init_core(core_t *core);
int event_handling(core_t *core);
int refresh_all(core_t *core);
void destroy_all(core_t *core);
void music_start(scene_t *scene, char *scene_id, bool status, float volume);

#endif /* !MY_RPG_H_ */