/*
** EPITECH PROJECT, 2022
** B-PSU-200-MAR-2-1-tetris-camillia.hammou
** File description:
** ncurse_tetris
*/

#include "my.h"

void write_only(WINDOW *window, int y, int x, char *text)
{
    mvwprintw(window, y, x, text);
}

void write_and_refresh(WINDOW *window, int y, int x, char *text)
{
    mvwprintw(window, y, x, text);
    wrefresh(window);
}

void start_and_create_colors()
{
    start_color();
    init_pair(RED_COLOR, COLOR_RED, COLOR_BLACK);
    init_pair(GREEN_COLOR, COLOR_GREEN, COLOR_BLACK);
    init_pair(YELLOW_COLOR, COLOR_YELLOW, COLOR_BLACK);
    init_pair(BLUE_COLOR, COLOR_BLUE, COLOR_BLACK);
    init_pair(MAGENTA_COLOR, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(CYAN_COLOR, COLOR_CYAN, COLOR_BLACK);
}

int start_game(int ac, char **av)
{
    WINDOW *window = initscr();
    curs_set(0);
    new_tetris_game();
    start_and_create_colors();
    noecho();
    nodelay(window, TRUE);
    while (1) {
        check_window_size(window);
        handle_key_press();
        if (!get_tetris_game()->paused) {
            update_menu();
            if (!get_tetris()->without_next) {
                update_next();
            }
            update_tetris_text();
            update_play();
        }
    }
    endwin();
    return (0);
}
