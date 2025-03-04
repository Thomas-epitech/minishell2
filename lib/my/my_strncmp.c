/*
** EPITECH PROJECT, 2025
** lib
** File description:
** my strncmp
*/

int my_strncmp(const char *s1, const char *s2, int n)
{
    for (int i = 0; (s1[i] != '\0' || s2[i] != '\0') && i < n; i++) {
        if ((s1[i] == 0) ^ (s2[i] == 0))
            return s1[i] == 0 ? 1 : -1;
        if (s1[i] != s2[i])
            return s1[i] > s2[i] ? 1 : -1;
    }
    return 0;
}
