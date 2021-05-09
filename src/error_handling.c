/*
** EPITECH PROJECT, 2021
** error_handling
** File description:
** error_handling
*/

#include <stdlib.h>

int error_handling(int ac, char **env)
{
    if (ac != 1 || !env[0])
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
