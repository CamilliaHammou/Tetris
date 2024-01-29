/*
** EPITECH PROJECT, 2022
** Tetris
** File description:
** play_window
*/

#include "my.h"

WINDOW *create_play_window(void)
{
    int height = 25;
    int width = 25;
    int y = 0;
    int x = 40;
    WINDOW *game = newwin(height, width, y, x);
    refresh();
    box(game, 0, 0);
    return (game);
}

void update_moving_tetrimino(WINDOW *window, moving_tetrimino_t *moving_tetrimino)
{
    print_tetrimino(window, moving_tetrimino->y_position, moving_tetrimino->x_position, moving_tetrimino);
}

void reset_game()
{
    if (get_tetris_game()->score > get_tetris_game()->high_score) {
        get_tetris_game()->high_score = get_tetris_game()->score;
    }
    get_tetris_game()->score = 0;
    get_tetris_game()->level = get_tetris()->level;
    get_tetris_game()->lines = 0;
    for (int y = 1; y < 24; y++) {
        for (int x = 1; x < 24; x++) {
            mvwaddch(get_tetris_game()->play_window, y, x,' ');
        }
    }
    switch_to_next();
}

void force_move_down()
{
    if (!move_tetrimino(get_tetris_game()->current_moving_tetrimino, 1, 0)) {
        if (get_tetris_game()->current_moving_tetrimino->y_position <= 1) {
            reset_game();
        } else {
            switch_to_next();
        }
    }
    get_tetris_game()->last_clock = clock();
}

void handle_key_press()
{
    int key = getch();
    if (key == ERR) {
        return;
    }
    if (key == get_tetris()->key_quit) {
        endwin();
        exit(0);
    }
    if (key == get_tetris()->key_drop) {
        force_move_down();
    }
    if (key == get_tetris()->key_left) {
        move_tetrimino(get_tetris_game()->current_moving_tetrimino, 0, -1);
    }
    if (key == get_tetris()->key_right) {
        move_tetrimino(get_tetris_game()->current_moving_tetrimino, 0, 1);
    }
    if (key == get_tetris()->key_turn) {
        //move_tetrimino(get_tetris_game()->current_moving_tetrimino, -1, 0);
    }
    if (key == get_tetris()->key_pause) {
        get_tetris_game()->paused = !get_tetris_game()->paused;
    }
}

void update_play()
{
    box(get_tetris_game()->play_window, 0, 0);
    if (get_elapsed_time(get_tetris_game()->last_second) > 1) {
        get_tetris_game()->elapsed_second++;
        get_tetris_game()->last_second = clock();
    }
    double delay = 0.5 - (get_tetris_game()->level * 0.05);
    if (delay <= 0.01) {
        delay = 0.01;
    }
    if (get_elapsed_time(get_tetris_game()->last_clock) > delay) {
        force_move_down();
    }
    update_moving_tetrimino(get_tetris_game()->play_window, get_tetris_game()->current_moving_tetrimino);
}

double get_elapsed_time(int last_time)
{
    int current_time = clock();
    double time = (double)(current_time - last_time) / CLOCKS_PER_SEC;
    return time;
}