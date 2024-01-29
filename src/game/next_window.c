/*
** EPITECH PROJECT, 2022
** Tetris
** File description:
** next_window
*/

#include "my.h"

WINDOW *create_next_window(void)
{
    int height = 10;
    int width = 21;
    int y = 0;
    int x = 65;
    WINDOW *next = newwin(height, width, y, x);
    refresh();
    box(next, 0, 0);
    return (next);
}

void switch_to_next()
{
    check_lines();
    for (int y = 1; y < 9; y++) {
        for (int x = 1; x < 20; x++) {
            mvwaddch(get_tetris_game()->next_window, y, x,' ');
        }
    }
    get_tetris_game()->current_moving_tetrimino = get_tetris_game()->next_moving_tetrimino;
    get_tetris_game()->next_moving_tetrimino = create_moving_tetrimino();
}

void update_next()
{
    box(get_tetris_game()->next_window, 0, 0);
    write_and_refresh(get_tetris_game()->next_window, 0, 8, "NEXT");
    print_tetrimino(get_tetris_game()->next_window, 3, 8, get_tetris_game()->next_moving_tetrimino);
}
