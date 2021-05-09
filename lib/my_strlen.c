/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** my_strlen
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int n = 0;

    for (; str[n] != '\0'; ++n);
    return (n);
}