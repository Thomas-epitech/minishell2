/*
** EPITECH PROJECT, 2025
** lib
** File description:
** signal messages header
*/

#ifndef SIGNAL_MESSAGES_H
    #define SIGNAL_MESSAGES_H

    #define NB_SIGNALS 32

[[maybe_unused]] static const char *signal_messages[] = {
    "Hangup",
    "Interrupt",
    "Quit",
    "Illegal instruction",
    "Trace/BPT trap",
    "Abort",
    "Bus error",
    "Floating exception",
    "Killed",
    "User signal 1",
    "Segmentation fault",
    "User signal 2",
    "Broken pipe",
    "Alarm clock",
    "Terminated",
    "Stack limit exceeded",
    "Child exited",
    "Continued",
    "Suspended (signal)",
    "Suspended",
    "Suspended (tty input)"
    "Suspended (tty output)",
    "Urgent condition on socket",
    "",
    "Cputime limit exceeded",
    "Filesize limit exceeded",
    "Virtual time alarm",
    "Profiling time alarm",
    "I/O now possible",
    "Pollable event occurred",
    "Power failure",
    "Bad system call"
};

const char *get_signal_message(unsigned signal);

#endif //SIGNAL_MESSAGES_H
