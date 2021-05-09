/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-mydefender-mateo.viel
** File description:
** list
*/

#include "csfml.h"
#include "struct.h"

void put_at_end_list(game_object_t **list, game_object_t *node)
{
    game_object_t *tmp = *list;

    if (node == NULL)
        return;
    if (tmp == NULL) {
        tmp = node;
        *list = tmp;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = node;
}