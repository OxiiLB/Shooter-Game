/*
** EPITECH PROJECT, 2022
** error.c
** File description:
** Check for an error at the begining of the project.
*/

#include "header.h"
#include <stdbool.h>
#include <string.h>

bool is_error(const char *const *env)
{
    int count_lines = 0;
    char *str = "DISPLAY=:";

    while (env[count_lines] != NULL) {
        if (my_strncmp(str, env[count_lines], 9) == 0)
            return false;
        count_lines = count_lines + 1;
    }
    return true;
}
