/*
** EPITECH PROJECT, 2022
** Tetris
** File description:
** menu_window
*/

#include "my.h"

WINDOW *create_menu_window(void)
{
    int height = 11;
    int width = 25;
    int y = 7;
    int x = 0;
    WINDOW *menu = newwin(height, width, y, x);
    refresh();
    box(menu, 0, 0);
    return (menu);
}

void write_text_with_num(char *text, int number, int y, int x)
{
    write_and_refresh(get_tetris_game()->menu_window, y, x, text);
    char *number_str = itoa(number);
    write_and_refresh(get_tetris_game()->menu_window, y, 20 - my_strlen(number_str), number_str);
}

void update_menu()
{
    box(get_tetris_game()->menu_window, 0, 0);
    write_text_with_num("High score", get_tetris_game()->high_score, 1, 2);
    write_text_with_num("Score", get_tetris_game()->score, 2, 2);

    write_text_with_num("Lines", get_tetris_game()->lines, 5, 2);
    write_text_with_num("Level", get_tetris_game()->level, 6, 2);
    
    write_text_with_num("Timer", get_tetris_game()->elapsed_second, 9, 2);
}