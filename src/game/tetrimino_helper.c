/*
** EPITECH PROJECT, 2022
** Tetris
** File description:
** tetrimino_helper
*/

#include "my.h"

void print_tetrimino(WINDOW *window, int y, int x, moving_tetrimino_t *moving_tetrimino)
{
    int color = (moving_tetrimino->tetrimino->color) % 6;
    wattron(window, COLOR_PAIR(color));
    for (int i = 0; i < moving_tetrimino->tetrimino->y; i++) {
        for (int a = 0; a < moving_tetrimino->tetrimino->x; a++) {
            char value = moving_tetrimino->tetrimino->clean_map[i][a];
            if (value == '*') {
                mvwaddch(window, y + i, x + a, value);
            }
        }
    }
    wrefresh(window);
    wattroff(window, COLOR_PAIR(color));
}

bool move_tetrimino(moving_tetrimino_t *moving_tetrimino, int y, int x)
{
    int new_y = moving_tetrimino->y_position + y;
    int new_x = moving_tetrimino->x_position + x;
    if (!can_move(moving_tetrimino, new_y, new_x)) {
        return false;
    }
    for (int y = 0; y < moving_tetrimino->tetrimino->y; y++) {
        for (int x = 0; x < moving_tetrimino->tetrimino->x; x++) {
            char tetrimino_point = moving_tetrimino->tetrimino->clean_map[y][x];
            char old_point = mvwinch(get_tetris_game()->play_window, moving_tetrimino->y_position + y, moving_tetrimino->x_position + x);
            if (old_point == '*' && tetrimino_point == '*') {
                mvwaddch(get_tetris_game()->play_window, moving_tetrimino->y_position + y, moving_tetrimino->x_position + x,' ');
            }
        }
    }
    moving_tetrimino->y_position = new_y; 
    moving_tetrimino->x_position = new_x;
    return true;
}

tetrimino_t *get_random_tetrimino(moving_tetrimino_t *moving_tetrimino)
{
    int random = random_in_range(0, get_tetrimino_manager()->size - 1);
    tetrimino_t *tetrimino = get_tetrimino_manager()->tetriminos[random];
    int alternative = 0;
    while (true) {
        if (tetrimino->valid) {
            moving_tetrimino->id = random;
            break;
        }
        moving_tetrimino->id = alternative;
        tetrimino = get_tetrimino_manager()->tetriminos[alternative++];
    }
    return tetrimino;
}

moving_tetrimino_t *create_moving_tetrimino()
{
    moving_tetrimino_t *moving_tetrimino = malloc(sizeof(moving_tetrimino_t));
    moving_tetrimino->tetrimino = get_random_tetrimino(moving_tetrimino);
    moving_tetrimino->y_position = 1;
    moving_tetrimino->x_position = 10;
    return moving_tetrimino;
}