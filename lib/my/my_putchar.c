/*
** EPITECH PROJECT, 2025
** lib
** File description:
** my putchar
*/

#include <unistd.h>

void my_putchar(const char c)
{
    write(1, &c, 1);
}
