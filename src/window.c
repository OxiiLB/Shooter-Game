/*
** EPITECH PROJECT, 2022
** window.c
** File description:
** Create a window with CSFML library.
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>

sfRenderWindow *create_window(const char *name, sfVector2i dimensions)
{
    sfVideoMode mode = {dimensions.x, dimensions.y, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, name,
    sfClose, NULL);
    sfRenderWindow_setPosition(window, (sfVector2i){0, 0});
    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}
