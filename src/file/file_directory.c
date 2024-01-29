/*
** EPITECH PROJECT, 2022
** Tetris
** File description:
** file_directory
*/

#include "my.h"

bool end_with(char *content, char *search)
{
    int search_size = my_strlen(search);
    int content_size = my_strlen(content);
    int diff = content_size - search_size;
    if (search_size > content_size) {
        return false;
    }
    for (int i = search_size; i >= 0; i--) {
        if (search[i] != content[diff + i]) {
            return false;
        }
    }
    return true;
}

char *my_strcat(char *dest, char *src)
{
    int i, x;
    for (i = 0; dest[i] != '\0'; i++);
    for (x = 0; src[x] != '\0'; x++) {
        dest[i + x] = src[x];
    }
    dest[i + x] = '\0';
    return dest;
}

char *get_path_name(struct dirent *entity)
{
    char *result = malloc(sizeof(char) * 50);
    my_strcat(result, "tetriminos/");
    my_strcat(result, entity->d_name);
    return result;
}
