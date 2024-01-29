/*
** EPITECH PROJECT, 2022
** Tetris
** File description:
** line_checker
*/

#include "my.h"

void all_down(int y_pos)
{
    wattron(get_tetris_game()->play_window, COLOR_PAIR(get_tetris_game()->lines % 5));
    for (int y = y_pos; y > 2; y--) {
        for (int x = 1; x < 24; x++) {
            char point = mvwinch(get_tetris_game()->play_window, y - 1, x);
            mvwaddch(get_tetris_game()->play_window, y - 1, x, ' ');
            mvwaddch(get_tetris_game()->play_window, y, x, point);
        }
    }
    wattroff(get_tetris_game()->play_window, COLOR_PAIR(get_tetris_game()->lines % 5));
}

void clean_line(int y)
{
    get_tetris_game()->score = (get_tetris_game()->score * 1.1) + 1;
    if (++get_tetris_game()->lines % 10 == 0) {
        get_tetris_game()->level++;
    }
    for (int x = 1; x < 24; x++) {
        mvwaddch(get_tetris_game()->play_window, y, x,' ');
    }
    all_down(y);
}

void check_lines()
{
    for (int y = 1; y < 24; y++) {
        for (int x = 1; x < 24; x++) {
            char point = mvwinch(get_tetris_game()->play_window, y, x);
            if (point != '*') {
                break;
            }
            if (x >= 23) {
                clean_line(y);
            }
        }
    }
}