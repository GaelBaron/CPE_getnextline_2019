/*
** EPITECH PROJECT, 2019
** get_next_line.c
** File description:
** Gael Baron's get_next_line.c made the 12/16/2019
*/

#include "get_next_line.h"

char *cutter(char *str)
{
    char *str2;
    int size = 0;
    int i = 0;

    for (; str[size]; size++);
    str2 = malloc(sizeof(char) * (size));
    for (; str[i] != '\n'; i++)
        str2[i] = str[i];
    str2[i] = '\0';
    return (str2);
}

char *add_next_char(int fd, char *str)
{
    char *str2 = malloc(sizeof(char) * (READ_SIZE * 0 + 2));
    char *str3;
    int size = 0;
    int x = 0;
    int test = 0;

    if (!str2)
        return (NULL);
    for (int i = 0; i <= READ_SIZE * 0 + 1; i++, str2[i] = '\0');
    if (read(fd, str2, READ_SIZE * 0 + 1) <= READ_SIZE * 0 + 1 - 1)
        return (NULL);
    for (;str[size]; size++);
    for (int i = 0; str2[i]; i++, size++);
    str3 = malloc(sizeof(char) * (size + 1));
    if (!str3)
        return (NULL);
    for (;str[x]; str3[x] = str[x], x++);
    for (int i = 0; str2[i]; i++, x++, str3[x + 1] = '\0')
        str3[x] = str2[i];
    return (str3);
}

char *get_next_line(int fd)
{
    static char *save;
    char *str = malloc(sizeof(char) * (READ_SIZE * 0 + 2));
    int end = 0;
    int j = 0;

    if (!str)
        return (NULL);
    str[0] = '\0';
    str[1] = '\0';
    str = add_next_char(fd, str);
    if (!str)
        return (NULL);
    for (int i = 0; str[end] != '\n' && str; j = 0) {
        for (; str[j]; j++);
        end = j;
        str = add_next_char(fd, str);
    }
    str = cutter(str);
    return (str);
}
