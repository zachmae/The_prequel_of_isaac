/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** my_rpg
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_rpg, test_1, .init = redirect_all_std)
{
    int count = 0;
    char **av = malloc(sizeof (char *) * 3);
    av[0] = strdup("./a.out");
    av[1] = strdup("-h");
    av[2] = NULL;
    print_usage(2, av);
    cr_assert_eq(count, 0);
}

Test(my_rpg, test_2, .init = redirect_all_std)
{
    int count = 0;
    char **av = malloc(sizeof (char *) * 3);
    av[0] = strdup("./a.out");
    av[1] = strdup("kh");
    av[2] = NULL;
    print_usage(2, av);
    cr_assert_eq(count, 0);
}

Test(my_rpg, test_3, .init = redirect_all_std)
{
    int count = 0;
    char **av = malloc(sizeof (char *) * 3);
    av[0] = strdup("./a.out");
    av[1] = strdup("-k");
    av[2] = NULL;
    print_usage(2, av);
    cr_assert_eq(count, 0);
}