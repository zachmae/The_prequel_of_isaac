/*
** EPITECH PROJECT, 2021
** en_travaux
** File description:
** my_arraylen
*/

#include <stdio.h>

int my_array_len(char **tab)
{
    int nb = 0;

    for (; tab[nb] != NULL; nb++);
    return (nb);
}