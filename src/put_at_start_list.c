/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-mydefender-mateo.viel
** File description:
** list
*/

#include "csfml.h"
#include "struct.h"

void put_at_start_list(game_object_t **list, game_object_t *node)
{
    game_object_t *tmp = *list;

    if (tmp == NULL) {
        tmp = node;
        *list = tmp;
        return;
    }
    node->next = *list;
    *list = node;
}