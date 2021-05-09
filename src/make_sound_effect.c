/*
** EPITECH PROJECT, 2021
** make sound effect
** File description:
** create sound effect
*/

#include <stdlib.h>
#include "csfml.h"
#include "struct.h"

sound_t *make_sound_effect(char *path)
{
    sound_t *sfx = malloc(sizeof(sound_t));

    sfx->sound = sfSound_create();
    sfx->buffer = sfSoundBuffer_createFromFile(path);
    sfSound_setBuffer(sfx->sound, sfx->buffer);
    return (sfx);
}
