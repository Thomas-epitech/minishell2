/*
** EPITECH PROJECT, 2025
** lib
** File description:
** my strlen
*/

int my_strlen(const char *str)
{
    int len = 0;

    while (str[len] != '\0')
        len++;
    return len;
}
