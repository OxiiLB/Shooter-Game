/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Main function of the project.
*/

#include "header.h"
#include "my.h"
#include <unistd.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/System/Export.h>

static void flag_help(void)
{
    my_printf("Welcome to Cyberponk 2007.\nThe goal is simple, \
shoot as many cyberducks as you can by clicking on them with the left \
button of your mouse.\nIf you want to play, write ./my_hunter in the \
terminal of your device.\nGood Luck Netrunner !");
}

int main(int argc, char **argv, const char *const *env)
{
    sfClock *clock;
    sfTime time;
    float seconds = 0;
    clock = sfClock_create();
    if (is_error(env))
        return 84;
    if (argc == 2 && my_strncmp(argv[1], "-h", 1) == 0) {
        flag_help();
        return 0;
    } else if (argc > 2 || (argc >= 2 && my_strncmp(argv[1], "-h", 1) != 0)) {
        write(2, "Error: cannot take this flag, -h for help.\n", 44);
        return 84;
    }
    sfRenderWindow *window = create_window("Cyberponk 2007",
    (sfVector2i){1920, 1080});
    return my_hunter(clock, time, seconds, window);
}
