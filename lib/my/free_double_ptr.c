/*
** EPITECH PROJECT, 2025
** lib
** File description:
** mini printf
*/

#include <stdlib.h>

void free_double_ptr(void **ptr)
{
    if (ptr == NULL)
        return;
    for (int i = 0; ptr[i] != NULL; i++)
        free(ptr[i]);
    free(ptr);
}
