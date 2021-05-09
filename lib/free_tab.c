/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** free_tab
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

void free_tab(char **tab)
{
    int nb = 0;

    for (nb = 0; tab[nb] != NULL; nb++);
    for (int i = 0; i < nb; i++)
        free(tab[i]);
    free(tab);
}