/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-malek.gatoufi
** File description:
** create_game_object
*/

#ifndef CREATE_GAME_OBJECT_H_
#define CREATE_GAME_OBJECT_H_
#include "struct.h"

game_object_t *create_static_sprite(sfIntRect rect, char *texture,
sfVector2f position, sfVector2f scale);
game_object_t *create_game_buttons(sfIntRect rect, char *texture,
int *stats, sfVector2f *position);
game_object_t *create_enemy(init_enemy_t *enemy, sfVector2f position);
game_object_t *create_text(sfVector2f position, int height, char *str);
void make_particles_mov(game_object_t **objs);
game_object_t *create_particle(sfVector2f pos, int count, ...);

#endif /* !CREATE_GAME_OBJECT_H_ */