/*
** EPITECH PROJECT, 2021
** my rpg
** File description:
** handle playerlevel
*/

#include "my.h"
#include "csfml.h"
#include "struct.h"
#include "buttons.h"

void level_handle(int stats[6])
{
    stats[XP] += 2;
    if (stats[XP] >= 10) {
        stats[XP] -= 10;
        stats[LEVEL] += 1;
        stats[POINT] += 1;
    }
}

void attack_up(core_t *core)
{
    if (core->stats[POINT] >= 1) {
        core->stats[ATTACK]++;
        core->stats[POINT]--;
    }
}

void speed_up(core_t *core)
{
    if (core->stats[POINT] >= 1) {
        core->stats[SPEED] += 2;
        core->stats[POINT]--;
    }
}

void life_up(core_t *core)
{
    if (core->stats[POINT] >= 1 && core->stats[LIFE] < 6) {
        core->stats[LIFE]++;
        core->stats[POINT]--;
    }
}

void go_scene_inventory(struct core_s *core)
{
    music_stop(core->scene, core->id_scene, core->status.music);
    core->id_scene = "inventory";
    music_start(core->scene, core->id_scene,
        core->status.music, core->status.volume);
    return;
}