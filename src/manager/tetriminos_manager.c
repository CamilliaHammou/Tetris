/*
** EPITECH PROJECT, 2022
** Tetris
** File description:
** tetriminos_manager
*/

#include "my.h"

static tetriminos_manager_t *tetriminos_manager;
static int size;

tetriminos_manager_t *get_tetrimino_manager(void)
{
    return tetriminos_manager;
}

tetrimino_t *create_tetrimino(char *filepath)
{
    tetrimino_t *tetrimino = malloc(sizeof(tetrimino_t));
    tetrimino->file = create_file_reader(filepath);
    set_tetrimino_content(tetrimino);
    return tetrimino;
}

void add_tetrimino(tetrimino_t *tetrimino, char *name)
{
    tetrimino->name = malloc(sizeof(name));
    my_strcat(tetrimino->name, remove_extension(name));
    tetriminos_manager->tetriminos[size++] = tetrimino;
    tetriminos_manager->size = size;
}

void extract_tetriminos(void)
{
    DIR *dir = opendir(TETRIMINOS);
    if (dir == NULL) {
        closedir(dir);
        return;
    }
    struct dirent *entity = readdir(dir);
    while (entity != NULL) {
        if (end_with(entity->d_name, "tetrimino")) {
            char *path = get_path_name(entity);
            add_tetrimino(create_tetrimino(path), entity->d_name);
        }
        entity = readdir(dir);
    }
    closedir(dir);
}

void new_tetriminos_manager(void)
{
    tetriminos_manager = malloc(sizeof(tetriminos_manager_t));
    tetriminos_manager->tetriminos = malloc(sizeof(tetrimino_t*) * 50);
    extract_tetriminos();
}
