/*
** EPITECH PROJECT, 2022
** workshop.c
** File description:
** Loop function of the csfml project.
*/

#include "my.h"
#include "header.h"
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/System/Export.h>

static void timer(float seconds, sfSprite *sprite, sfClock *clock,
sfIntRect *rect)
{
    if (seconds >= 0.25) {
        rect->left += 110;
        sfClock_restart(clock);
        if (rect->left > 220) {
            rect->left = 0;
        }
    } else if (seconds > 0.01) {
        sfSprite_move(sprite, (sfVector2f){15, 0});
    } else {
        return;
    }
}

sfVector2f scaling(sfSprite *sprite)
{
    float size = ((float)rand() / (float)(RAND_MAX)) + 0.75;
    sfSprite_setScale(sprite, (sfVector2f){size, size});
    sfVector2f scale = sfSprite_getScale(sprite);
    return scale;
}

static int game_loop(sfRenderWindow *window, sfSprite *sprite,
sfVector2f scale, int pv)
{
    pv = analyse_events(window, sprite, scale, pv);
    if (pv == 0)
        sfRenderWindow_close(window);
    sfRenderWindow_clear(window, sfRed);
    return pv;
}

static void draw_all(sfRenderWindow *window, sfSprite *s_wallpaper,
sfSprite *sprite)
{
    sfRenderWindow_drawSprite(window, s_wallpaper, NULL);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_display(window);
}

int my_hunter(sfClock *clock, sfTime time, float seconds,
sfRenderWindow *window)
{
    sfIntRect rect = generate_rect(0, 0, 110, 110);
    sfTexture *t_wallpaper = sfTexture_createFromFile("map.jpg", NULL);
    sfSprite *s_wallpaper = create_sprite((sfVector2f){0, 0}, t_wallpaper);
    sfTexture *texture = sfTexture_createFromFile("sprite_canard.png", NULL);
    sfSprite *sprite = create_sprite((sfVector2f){0, (rand() % 450)}, texture);
    int check = checking_text(t_wallpaper, texture);
    sfVector2f scale = scaling(sprite);
    int pv = 3;
    while (sfRenderWindow_isOpen(window)) {
        pv = game_loop(window, sprite, scale, pv);
        time = sfClock_getElapsedTime(clock);
        sfSprite_setTextureRect(sprite, rect);
        seconds = time.microseconds / 1000000.0;
        timer(seconds, sprite, clock, &rect);
        draw_all(window, s_wallpaper, sprite);
    }
    destroy(window, sprite, texture);
    destroy2(s_wallpaper, t_wallpaper, clock);
    return check;
}
