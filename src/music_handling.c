/*
** EPITECH PROJECT, 2021
** my rpg project
** File description:
** music handling
*/

#include "struct.h"
#include "my.h"

void music_start(scene_t *scene, char *scene_id, bool status, float volume)
{
    if (status != true)
        return;
    for (int c = 0; scene[c].name != NULL; c++) {
        if (my_strcmp(scene_id, scene[c].name) == 0) {
            sfMusic_play(scene[c].music);
            sfMusic_setVolume(scene[c].music, volume);
            sfMusic_setLoop(scene[c].music, true);
        }
    }
}

void music_stop(scene_t *scene, char *scene_id, bool status)
{
    if (status != true)
        return;
    for (int c = 0; scene[c].name != NULL; c++) {
        if (my_strcmp(scene_id, scene[c].name) == 0)
            sfMusic_stop(scene[c].music);
    }
}