/*
** EPITECH PROJECT, 2022
** Tetris
** File description:
** tetris_text_window
*/

#include "my.h"

/*  
    my_putstr("*** *** *** *** * *** \n");
    my_putstr(" *  *    *  * *   *   \n");
    my_putstr(" *  **   *  **  * *** \n");
    my_putstr(" *  *    *  * * *   * \n");
    my_putstr(" *  ***  *  * * * *** \n");
*/

WINDOW *create_tetrix_text_window(void)
{
    int height = 7;
    int width = 40;
    int y = 0;
    int x = 0;
    WINDOW *menu = newwin(height, width, y, x);
    refresh();
    //box(menu, 0, 0);
    return (menu);
}

void print_tetris_two(void)
{
    wattron(get_tetris_game()->tetris_text_window, COLOR_PAIR(BLUE_COLOR));
    write_only(get_tetris_game()->tetris_text_window, 1, 22, "* * *");
    write_only(get_tetris_game()->tetris_text_window, 2, 22, "*   *");
    write_only(get_tetris_game()->tetris_text_window, 3, 22, "* *");
    write_only(get_tetris_game()->tetris_text_window, 4, 22, "*   *");
    write_only(get_tetris_game()->tetris_text_window, 5, 22, "*   *");
    wattron(get_tetris_game()->tetris_text_window, COLOR_PAIR(GREEN_COLOR));
    write_only(get_tetris_game()->tetris_text_window, 1, 29, "*");
    write_only(get_tetris_game()->tetris_text_window, 3, 29, "*");
    write_only(get_tetris_game()->tetris_text_window, 4, 29, "*");
    write_only(get_tetris_game()->tetris_text_window, 5, 29, "*");
    wattron(get_tetris_game()->tetris_text_window, COLOR_PAIR(YELLOW_COLOR));
    write_only(get_tetris_game()->tetris_text_window, 1, 32, "* * *");
    write_only(get_tetris_game()->tetris_text_window, 2, 32, "*");
    write_only(get_tetris_game()->tetris_text_window, 3, 32, "* * *");
    write_only(get_tetris_game()->tetris_text_window, 4, 36, "*");
    write_only(get_tetris_game()->tetris_text_window, 5, 32, "* * *");
}

void print_title(void)
{
    wattron(get_tetris_game()->tetris_text_window, COLOR_PAIR(CYAN_COLOR));
    write_only(get_tetris_game()->tetris_text_window, 1, 1, "* * *");
    write_only(get_tetris_game()->tetris_text_window, 2, 3, "*");
    write_only(get_tetris_game()->tetris_text_window, 3, 3, "*");
    write_only(get_tetris_game()->tetris_text_window, 4, 3, "*");
    write_only(get_tetris_game()->tetris_text_window, 5, 3, "*");
    wattron(get_tetris_game()->tetris_text_window, COLOR_PAIR(GREEN_COLOR));
    write_only(get_tetris_game()->tetris_text_window, 1, 8, "* * *");
    write_only(get_tetris_game()->tetris_text_window, 2, 8, "*");
    write_only(get_tetris_game()->tetris_text_window, 3, 8, "* *");
    write_only(get_tetris_game()->tetris_text_window, 4, 8, "*");
    write_only(get_tetris_game()->tetris_text_window, 5, 8, "* * *");
    wattron(get_tetris_game()->tetris_text_window, COLOR_PAIR(MAGENTA_COLOR));
    write_only(get_tetris_game()->tetris_text_window, 1, 15, "* * *");
    write_only(get_tetris_game()->tetris_text_window, 2, 17, "*");
    write_only(get_tetris_game()->tetris_text_window, 3, 17, "*");
    write_only(get_tetris_game()->tetris_text_window, 4, 17, "*");
    write_only(get_tetris_game()->tetris_text_window, 5, 17, "*");
    print_tetris_two();
}

void update_tetris_text()
{
    wattroff(get_tetris_game()->tetris_text_window, COLOR_PAIR(CYAN_COLOR));
    //wattron(get_tetris_game()->tetris_text_window, COLOR_PAIR(CYAN_COLOR));
    /*write_only(get_tetris_game()->tetris_text_window, 1, 1, "*** *** *** *** * *** ");
    write_only(get_tetris_game()->tetris_text_window, 2, 1, " *  *    *  * *   *   ");
    write_only(get_tetris_game()->tetris_text_window, 3, 1, " *  **   *  **  * *** ");
    write_only(get_tetris_game()->tetris_text_window, 4, 1, " *  *    *  * * *   * ");
    write_only(get_tetris_game()->tetris_text_window, 5, 1, " *  ***  *  * * * *** ");*/
    print_title();
    wrefresh(get_tetris_game()->tetris_text_window);
    //wattroff(get_tetris_game()->tetris_text_window, COLOR_PAIR(CYAN_COLOR));
}