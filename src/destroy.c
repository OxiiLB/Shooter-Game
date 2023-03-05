/*
** EPITECH PROJECT, 2022
** destroy
** File description:
** destroy the window
*/

#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/System/Export.h>

void destroy(sfRenderWindow *window, sfSprite *sprite, sfTexture *texture)
{
    sfRenderWindow_destroy(window);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

void destroy2(sfSprite *s_wallpaper, sfTexture *t_wallpaper, sfClock *clock)
{
    sfSprite_destroy(s_wallpaper);
    sfTexture_destroy(t_wallpaper);
    sfClock_destroy(clock);
}
