/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_itoa
*/

#include <stdlib.h>
#include "my.h"

int count_len(int nb)
{
    int i = 0;
    for (; nb > 0; i++) {
        nb /= 10;
    }
    return i;
}

char *my_itoa(int nb)
{
    char *str = malloc(sizeof(int) * 1);
    int i = 0;

    if (nb == 0)
        return (my_strdup("0"));
    if (nb < 0) {
        nb = -nb;
        str[0] = '-';
        i++;
    }
    int len = count_len(nb);
    i += len;
    str[len] = '\0';
    while (len--) {
        i--;
        str[i] = nb % 10 + '0';
        nb /= 10;
    }
    return str;
}