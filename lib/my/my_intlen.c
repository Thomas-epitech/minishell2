/*
** EPITECH PROJECT, 2025
** lib
** File description:
** my intlen
*/

int my_intlen(int nb)
{
    int len = 0;

    if (nb == 0)
        return 1;
    while (nb != 0) {
        nb /= 10;
        len++;
    }
    return len;
}
