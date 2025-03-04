/*
** EPITECH PROJECT, 2025
** lib
** File description:
** my_sqrt
*/

double my_sqrt(const double x)
{
    for (int i = 0; i <= x; i++)
        if (i * i == x)
            return i;
    return -1;
}
