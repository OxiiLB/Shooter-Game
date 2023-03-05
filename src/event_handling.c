/*
** EPITECH PROJECT, 2022
** event_handling.c
** File description:
** Events handling.
*/

#include "my.h"
#include "header.h"
#include <stdlib.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/System/Export.h>

static void checking_duck_killed(sfEvent event, sfSprite *sprite,
sfVector2f scale)
{
    int sprite_x = sfSprite_getPosition(sprite).x;
    int sprite_y = sfSprite_getPosition(sprite).y;
    if (((event.mouseButton).x >= sprite_x) &&
    ((event.mouseButton).x <= sprite_x + (110 * scale.x))) {
        if (((event.mouseButton).y >= sprite_y) &&
        ((event.mouseButton).y <= sprite_y + (110 * scale.y))) {
            scale = scaling(sprite);
            sfSprite_setPosition(sprite, (sfVector2f)
            {0, (rand() % 450)});
        }
    }
}

int analyse_events(sfRenderWindow *window, sfSprite *sprite, sfVector2f scale,
int pv)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }

        if (event.type == sfEvtMouseButtonPressed) {
            checking_duck_killed(event, sprite, scale);
        }
    }
    if (sfSprite_getPosition(sprite).x >= 1920) {
        scale = scaling(sprite);
        sfSprite_setPosition(sprite, (sfVector2f)
        {0, (rand() % 450)});
        pv -= 1;
    }
    return pv;
}
