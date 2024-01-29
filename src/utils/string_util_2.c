/*
** EPITECH PROJECT, 2022
** Tetris
** File description:
** string_util_2
*/

#include "my.h"

char *remove_new_line(char *str)
{
    char *copy = malloc(sizeof(str));
    for (int i = 0; str[i] != '\0'; i++) {
        copy[i] = str[i] == '\n' ? '\0' : str[i];
    }
    return copy;
}

char *itoa(int number)
{
    char *str = malloc(sizeof(char) * 20);
    int count = 0;
    if (number == 0) {
        str[count++] = '0';
        str[count] = '\0';
        return str;
    }
    while (number != 0) {
        int remainder = number % 10;
        str[count++] = remainder + '0';
        number /= 10;
    }
    str[count] = '\0';
    my_revstr(str);
    return str;
}

char *remove_extension(char *str)
{
    char *result = malloc(sizeof(str));
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            break;
        }
        result[i] = str[i];
    }
    return result;
}

void print_without_size(tetrimino_t *tetrimino)
{
    for (int i = 1; tetrimino->map[i] != NULL; i++) {
        my_putstr(tetrimino->map[i]);
    }
}
