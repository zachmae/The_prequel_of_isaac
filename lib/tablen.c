/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-malek.gatoufi
** File description:
** tablen
*/

int tablen(char ***tab)
{
    int size = 0;

    for (int i = 0; tab[i]; ++i)
        size++;
    return (size);
}