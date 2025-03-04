/*
** EPITECH PROJECT, 2025
** lib
** File description:
** my put nbr
*/

#include "my.h"

int my_put_nbr(int nb)
{
    int len;

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    len = my_intlen(nb);
    while (len > 0) {
        my_putchar((char) (nb / my_pow(10, len - 1)) + 48);
        nb = (int) ((long) nb % (long) my_pow(10, len - 1));
        len--;
    }
    return 0;
}
