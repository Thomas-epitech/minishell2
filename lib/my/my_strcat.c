/*
** EPITECH PROJECT, 2025
** lib
** File description:
** my strcat
*/

#include <stdio.h>

#include "my.h"

char *my_strcat(char *dest, const char *src)
{
    const int dest_len = my_strlen(dest);
    const int src_len = my_strlen(src);

    for (int i = 0; src[i] != '\0'; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + src_len] = '\0';
    return dest;
}
