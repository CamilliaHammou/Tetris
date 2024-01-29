/*
** EPITECH PROJECT, 2022
** Tetris
** File description:
** string_util
*/

#include "my.h"

bool is_number(char value)
{
    return value >= '0' && value <= '9';
}

char **map_file_content(file_t *file)
{
    char *str = file->content;
    char **map = malloc(sizeof(char *) * file->columns);
    int x = 0, y = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (map[y] == NULL) {
            map[y] = malloc(sizeof(char) * file->hor_size);
        }
        map[y][x++] = str[i];
        if (str[i] == '\n') {
            y++;
            x = 0;
        }
    }
    return map;
}

int get_next_end_number(char *str, int start)
{
    bool found = false;
    for (int i = start; str[i] != '\0'; i++) {
        if (is_number(str[i])) {
            found = true;
        } else if (found) {
            return i;
        }
    }
}

char *extract_str(char *str, int start, int end)
{
    int counter = 0;
    char *copy = malloc(sizeof(str));
    for (int i = start; str[i] != '\0' && i <= end; i++) {
        copy[counter++] = str[i];
    }
    return copy;
}

int my_strlen(char const *str)
{
    int counter = 0;
    while (str[counter] != '\0')
        counter++;
    return counter - 1;
}

char *create_string(char *str, int size)
{
    char *result = malloc(sizeof(char) * size);
    for (int i = 0; str[i] != '\0'; i++) {
        result[i] = str[i];
    }
    return result;
}
