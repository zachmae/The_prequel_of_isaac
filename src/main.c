/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include <stdlib.h>
#include "main.h"

int main(int ac, char **av, char **env)
{
    if (print_usage(ac, av) == 1)
        return EXIT_SUCCESS;
    if (error_handling(ac, env) != EXIT_SUCCESS)
        return EXIT_ERROR;
    if (my_rpg() == (-1))
        return 84;
    return EXIT_SUCCESS;
}
