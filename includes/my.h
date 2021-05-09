/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** my
*/

#ifndef MY_H
#define MY_H


int my_putstr(char *str);
int my_puterror(char *str);
int my_strlen(char const *str);
char *my_strdup(char *str);
int my_strcmp(char *s1, char *s2);
char *my_strncpy(char *dest, char *str, int n);
char *my_itoa(int nb);
void free_tab(char **tab);
int my_array_len(char **tab);
char *init_buffer(char *filepath);
char **str_to_array(char flag, char *str2);
void my_free(char *list, ...);
int my_tablen(char ***tab);
int my_getnbr(char const *str);
char **my_tabdup(char **tab);
int tablen(char ***tab);

#endif /* !MY_H */
