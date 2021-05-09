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

void use_item_attack(core_t *core)
{
    if (core->items[ATTACK] >= 1) {
        core->stats[ATTACK]++;
        core->items[ATTACK]--;
    }
}

void use_item_speed(core_t *core)
{
    if (core->items[SPEED] >= 1) {
        core->stats[SPEED] += 5;
        core->items[SPEED]--;
    }
}

void use_item_life(core_t *core)
{
    if (core->items[LIFE] >= 1 && core->stats[LIFE] < 6) {
        core->stats[LIFE]++;
        core->items[LIFE]--;
    }
}