/*
** EPITECH PROJECT, 2021
** my_sokoban
** File description:
** my_putstr
*/

#include <unistd.h>
#include "my.h"

int my_putstr(char *str)
{
    write(1, str, my_strlen(str));
    return (0);
}

int my_puterror(char *str)
{
    write(2, str, my_strlen(str));
    return (0);
}

