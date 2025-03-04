/*
** EPITECH PROJECT, 2024
** my strdup
** File description:
** lib
*/

#include <stdlib.h>

#include "my.h"

char *my_strdup(const char *str)
{
    char *new_str = malloc(sizeof(char) * my_strlen(str) + 1);

    if (new_str == NULL)
        return NULL;
    my_strcpy(new_str, str);
    return new_str;
}
