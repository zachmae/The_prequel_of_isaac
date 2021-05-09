/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** del_lears
*/

#include "struct.h"
#include "my_player.h"
#include <stdlib.h>

int check_colis(lears_t *temp)
{
    sfVector2f pos = sfCircleShape_getPosition(temp->circle);

    if (pos.y <= 150 || pos.y >= 900 || pos.x <= 355 || pos.x >= 1600)
        return (-1);
    return (0);
}

int ene_len(lears_t *chain)
{
    int nb = 0;

    if (chain == NULL)
        return (nb);
    for (; chain->next != NULL; nb += 1)
        chain = chain->next;
    return (nb);
}

lears_t *pos_zero_e(lears_t *chain, lears_t *temp)
{
    temp = chain->next;
    free(chain);
    return (temp);
}

lears_t *del_lears(lears_t *chain, int pos)
{
    lears_t *temp = chain;
    lears_t *save = chain;
    int size = ene_len(chain);

    if (temp == NULL)
        return (NULL);
    if (pos == 0)
        return (pos_zero_e(chain, temp));
    for (int i = 0; i < pos && i < size; i++) {
        save = temp;
        temp = temp->next;
    }
    save->next = temp->next;
    return (chain);
}

void check_death(core_t *core)
{
    int c = find_scene("game", core);
    lears_t *temp = core->scene[c].player.larmes;

    for (int i = 0; temp != NULL; i = i + 1) {
        if (check_colis(temp) == -1) {
            core->scene[c].player.larmes = \
            del_lears(core->scene[c].player.larmes, i);
        }
        temp = temp->next;
    }
}