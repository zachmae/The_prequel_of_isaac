/*
** EPITECH PROJECT, 2021
** lib_csfml
** File description:
** my_csfml
*/

#ifndef MY_CSFML_H_
#define MY_CSFML_H_

#include <SFML/Graphics.h>
#include <SFML/Window.h>


sfBool coli_sprite(sfSprite *sprite, sfVector2i mouse);
void check_event(sfRenderWindow *win, sfEvent *event);
int button(sfSprite **sprite, sfRenderWindow *window, sfEvent *event);
sfVector2f add_vectorf(sfVector2f pos, sfVector2f pos1);
sfBool sprite_intersect(sfSprite *sprite1, sfSprite *sprite2);
sfSprite *create_my_sprite(char *filepath, sfTexture *Texture, sfIntRect *rect);
sfVector2i add_vectori(sfVector2i pos, sfVector2i pos1);
sfRenderWindow *create_my_window(int x, int y, int bbp, char *name);

#endif /* !MY_CSFML_H_ */
