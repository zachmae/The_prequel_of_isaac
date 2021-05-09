/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** my_strdup
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char *str)
{
    int len = my_strlen(str);

    char *str2 = malloc(sizeof(char) * len + 1);
    for (int i = 0; str[i] != '\0'; i++)
        str2[i] = str[i];
    str2[len] = '\0';
    return (str2);
}