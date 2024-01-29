/*
** EPITECH PROJECT, 2022
** Tetris
** File description:
** collision
*/

#include "my.h"

bool my_own_star(moving_tetrimino_t *moving_tetrimino, int pos_y, int pos_x)
{
    for (int y = 0; y < moving_tetrimino->tetrimino->y; y++) {
        for (int x = 0; x < moving_tetrimino->tetrimino->x; x++) {
            char tetrimino_point = moving_tetrimino->tetrimino->clean_map[y][x];
            if (tetrimino_point == '*' && pos_y == moving_tetrimino->y_position + y && pos_x == moving_tetrimino->x_position + x) {
                return true;
            }
        }
    }
    return false;
}

bool can_move(moving_tetrimino_t *moving_tetrimino, int new_y, int new_x)
{
    if (new_y < 1 || new_y > (24 - moving_tetrimino->tetrimino->y)) {
        return false;
    }
    if (new_x < 1 || new_x > (24 - moving_tetrimino->tetrimino->x)) {
        return false;
    }
    for (int y = 0; y < moving_tetrimino->tetrimino->y; y++) {
        for (int x = 0; x < moving_tetrimino->tetrimino->x; x++) {
            char new_point = mvwinch(get_tetris_game()->play_window, new_y + y, new_x + x);
            char old_point = mvwinch(get_tetris_game()->play_window, moving_tetrimino->y_position + y, moving_tetrimino->x_position + x);

            char tetrimino_point = moving_tetrimino->tetrimino->clean_map[y][x];
            if (old_point == '*' && new_point == '*' && !my_own_star(moving_tetrimino, new_y + y, new_x + x)) {
                return false;
            }
        }
    }
    return true;
}