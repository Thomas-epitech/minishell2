/*
** EPITECH PROJECT, 2025
** lib
** File description:
** my strncpy
*/

#include "my.h"

char *my_strncpy(char *dest, const char *src, const int n)
{
    for (int i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[n] = '\0';
    return dest;
}
