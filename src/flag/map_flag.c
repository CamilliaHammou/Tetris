/*
** EPITECH PROJECT, 2022
** Tetris
** File description:
** map_flag
*/

#include "my.h"

int find_comma(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ',') {
            return i;
        }
    }
    return -1;
}

void set_map_format(char *args)
{
    int comma = find_comma(args);
    char *row = extract_str(optarg, 0, comma - 1);
    char *col = extract_str(optarg, comma + 1, 20);
    get_tetris()->map_format->x = my_get_nbr(row);
    get_tetris()->map_format->y = my_get_nbr(col);
}
