/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** A function that reverses a string.
*/

void my_number_swap(char *a, char *b)
{
    char save = *a;
    *a = *b;
    *b = save;
}

char *my_revstr(char *str)
{
    int counter = 0;
    while (str[counter] != '\0') {
        counter++;
    }
    int a = 0;
    while (a < counter - 1) {
        my_number_swap(&str[a++], &str[counter-- - 1]);
    }
    return str;
}
