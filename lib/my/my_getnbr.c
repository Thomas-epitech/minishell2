/*
** EPITECH PROJECT, 2025
** lib
** File description:
** my getnbr
*/

static int get_sign(char const *str)
{
    int sign = 0;

    if (*str == '+' || (*str >= '0' && *str <= '9')) {
        sign = 1;
    }
    str++;
    while (*str == '+' || *str == '-') {
        if (*str == '-') {
            sign = !sign;
        }
        str++;
    }
    if (*str >= '0' && *str <= '9') {
        return sign;
    }
    return 2;
}

int my_getnbr(char const *str)
{
    int flag2 = 0;
    int final_nb = 0;
    int sign = 1;

    while (*str != '\0') {
        if (((*str == '+' || *str == '-') && get_sign(str) != 2) && !(flag2)) {
            flag2 = 1;
            sign = get_sign(str);
        }
        if (*str >= '0' && *str <= '9'){
            final_nb = final_nb * 10 + (*str - 48);
            flag2 = 1;
        }
        if (*str != '+' && *str != '-' && flag2 &&
            (*(str + 1) < '0' || *(str + 1) > '9'))
            break;
        str++;
    }
    return sign ? final_nb : -(final_nb);
}
