/*
** EPITECH PROJECT, 2021
** 01_Graphical
** File description:
** my_defender
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include "struct.h"
#include "my_rpg.h"

int my_rpg(void)
{
    core_t core;

    srand((long long int) &core);
    if (init_core(&core) == (-1))
        return (-1);
    music_start(core.scene, core.id_scene,
        core.status.music, core.status.volume);
    while (sfRenderWindow_isOpen(core.window)) {
        event_handling(&core);
        refresh_all(&core);
    }
    destroy_all(&core);
    return (0);
}