/*
** EPITECH PROJECT, 2022
** Tetris
** File description:
** tetrimino_integrity
*/

#include "my.h"

bool check_line_size(char *str, int expected)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            return i <= expected;
        }
    }
    return false;
}

bool check_tetrimino_integrity(tetrimino_t *tetrimino)
{
    char **map = tetrimino->map;
    for (int x = 0; map[0][x] != '\0'; x++) {
        char value = map[0][x];
        if (!is_number(value) && value != ' ' && value != '\n') {
            return false;
        }
    }
    int y = 1;
    while (map[y] != NULL) {
        if (!check_line_size(map[y], tetrimino->x)) {
            return false;
        }
        y++;
    }
    if (tetrimino->file->columns - 1 != y) {
        return false;
    }
    return true;
}
