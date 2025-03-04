/*
** EPITECH PROJECT, 2025
** lib
** File description:
** is_letter
*/

#include <stdbool.h>

bool is_letter(const char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
