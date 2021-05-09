/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-malek.gatoufi
** File description:
** update
*/

#ifndef UPDATE_H_
#define UPDATE_H_

void update_buttons(core_t *core, game_object_t *objs);
void update_minimap(core_t *core, game_object_t *obj);
void music_start(scene_t *scene, char *scene_id, bool status, float volume);
void music_stop(scene_t *scene, char *scene_id, bool status);
int my_rpg(void);
void update_room(core_t *core);

#endif /* !UPDATE_H_ */