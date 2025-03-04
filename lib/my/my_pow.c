/*
** EPITECH PROJECT, 2025
** lib
** File description:
** my pow
*/

#include <stdio.h>

double my_pow(double x, double y)
{
    double result = 1;

    for (int i = 0; i < y; i++)
        result *= x;
    return result;
}
