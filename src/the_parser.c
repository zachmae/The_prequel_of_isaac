/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** the_parser
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my.h"

int read_buffer(char *filepath, char **str, size_t size)
{
    char *buff = *str;
    int fd = open(filepath, O_RDONLY);
    if (fd == (-1))
        return (-1);
    if (read(fd, buff, size) == (-1))
        return (-1);
    buff[size] = '\0';
    str = &buff;
    return 0;
}

char ***the_parser(char *filepath)
{
    char *buffer = NULL;
    char ***parsed;
    char **tamp;
    struct stat buff;
    int i = 0;

    stat(filepath, &buff);
    buffer = malloc(sizeof(char) * (buff.st_size + 1));
    if (read_buffer(filepath, &buffer, buff.st_size) == (-1))
        return NULL;
    tamp = str_to_array('\n', buffer);
    parsed = malloc(sizeof(char **) * (my_array_len(tamp) + 1));
    for (; tamp[i] != NULL; ++i)
        parsed[i] = str_to_array(':', tamp[i]);
    parsed[i] = NULL;
    free(buffer);
    my_free("2", tamp);
    return parsed;
}