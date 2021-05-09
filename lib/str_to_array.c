/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** str_to_array
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int charcount_a(char flag, char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == flag)
            nb++;
    }
    return (nb + 1);
}

int counter_a(char flag, char *str)
{
    int nb = 0;

    for (; str[nb] != '\0'; nb++) {
        if (str[nb] == flag || str[nb] == '\n')
            break;
    }
    return (nb + 1);
}

char **str_to_array(char flag, char *str2)
{
    int nb = 0;
    char **array;
    char *str;
    if (str2 == NULL)
        return (NULL);
    str = my_strdup(str2);

    array = malloc(sizeof(char *) * (charcount_a(flag, str2) + 1));
    for (int i = 0; i < charcount_a(flag, str2); i++) {
        nb = counter_a(flag, str);
        array[i] = malloc(sizeof(char) * nb);
        array[i] = my_strncpy(array[i], str, nb - 1);
        str = str + nb;
        array[i][nb - 1] = '\0';
    }
    array[charcount_a(flag, str2)] = NULL;
    return (array);
}