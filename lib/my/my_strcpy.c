/*
** EPITECH PROJECT, 2025
** lib
** File description:
** my strcpy
*/

#include "my.h"

char *my_strcpy(char *dest, const char *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[my_strlen(src)] = '\0';
    return dest;
}
