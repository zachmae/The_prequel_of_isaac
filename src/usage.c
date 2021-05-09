/*
** EPITECH PROJECT, 2021
** usage
** File description:
** usage
*/

#include <unistd.h>

int print_usage(int ac, char **av)
{
    if (ac == 2)
        if (av[1][0] == '-' && av[1][1] == 'h') {
            write(1, "USAGE\n\t./my_rpg\n", 17);
            write(1, "DESCRIPTION\n\tthis is my rpg\n\tGLHF\n", 35);
            return 1;
        }
    return 0;
}