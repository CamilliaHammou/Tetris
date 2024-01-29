/*
** EPITECH PROJECT, 2022
** Tetris
** File description:
** tetrimino_content
*/

#include "my.h"

void extract_size(tetrimino_t *tetrimino, char *str)
{
    int start = 0;
    int end = get_next_end_number(str, start);
    char *x = extract_str(str, start, end);
    tetrimino->x = my_get_nbr(x);

    start = end + 1;
    end = get_next_end_number(str, start);
    char *y = extract_str(str, start, end);
    tetrimino->y = my_get_nbr(y);

    start = end + 1;
    end = get_next_end_number(str, start);
    char *color = extract_str(str, start, end);
    tetrimino->color = my_get_nbr(color);
}

char **get_cleaned_map(file_t *file)
{
    char *str = file->content;
    char **map = malloc(sizeof(char *) * file->columns);
    int x = 0, y = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (y > 0) {
            if (map[y - 1] == NULL) {
                map[y - 1] = malloc(sizeof(char) * file->hor_size);
            }
            map[y - 1][x++] = str[i];
        }
        if (str[i] == '\n') {
            y++;
            x = 0;
        }
    }
    return map;
}

void set_tetrimino_content(tetrimino_t *tetrimino)
{
    char *content = tetrimino->file->content;
    tetrimino->map = map_file_content(tetrimino->file);
    extract_size(tetrimino, tetrimino->map[0]);
    tetrimino->valid = check_tetrimino_integrity(tetrimino);
    if (tetrimino->valid) {
        tetrimino->clean_map = get_cleaned_map(tetrimino->file);
        get_tetris()->one_tetrimino_valid = true;
    }
}
