/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-malek.gatoufi
** File description:
** create_static_sprite
*/

#include <stdlib.h>
#include "csfml.h"
#include "struct.h"
#include "my.h"

game_object_t *create_text(sfVector2f position, int height, char *str)
{
    game_object_t *obj = malloc(sizeof(game_object_t));
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    obj->text = malloc(sizeof(text_t));
    obj->text->text = sfText_create();
    obj->text->str = my_strdup(str);
    sfText_setString(obj->text->text, str);
    sfText_setPosition(obj->text->text, position);
    sfText_setFont(obj->text->text, font);
    sfText_setCharacterSize(obj->text->text, height);
    obj->type = TEXT;
    obj->update = NULL;
    obj->next = NULL;
    return (obj);
}