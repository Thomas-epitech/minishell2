/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** get signal message
*/

#include "signal_messages.h"

const char *get_signal_message(const unsigned signal)
{
    if (signal == 0 || signal >= NB_SIGNALS)
        return "";
    return signal_messages[signal - 1];
}
