/*
** EPITECH PROJECT, 2025
** lib
** File description:
** my itoa
*/

#include <stdlib.h>

#include "my.h"

char *my_itoa(int nb)
{
    int nb_len = my_intlen(nb);
    char *result = malloc(sizeof(char) * (nb_len + 1));

    if (result == NULL)
        return NULL;
    for (int i = 0; i < nb_len; i++) {
        result[i] = (char) (nb / my_pow(10, nb_len - i - 1) + 48);
        nb = (int) (nb % (long) my_pow(10, nb_len - i - 1));
    }
    result[nb_len] = '\0';
    return result;
}
