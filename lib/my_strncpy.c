/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, char *str, int n)
{
    for (int i = 0; i < n; i++)
        dest[i] = str[i];
    return (dest);
}