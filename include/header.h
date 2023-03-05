/*
** EPITECH PROJECT, 2022
** header
** File description:
** header project
*/

#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/System/Export.h>
#include <stdbool.h>

#ifndef header
    #define header

    int my_hunter(sfClock *clock, sfTime time, float seconds,
    sfRenderWindow *window);
    bool is_error(const char *const *env);
    sfRenderWindow *create_window(const char *name, sfVector2i dimensions);
    sfSprite *create_sprite(sfVector2f position, sfTexture *texture);
    void destroy(sfRenderWindow *window, sfSprite *sprite,
    sfTexture *texture);
    int analyse_events(sfRenderWindow *window, sfSprite *sprite,
    sfVector2f scale, int pv);
    int my_strncmp(char const *s1, char const *s2, int n);
    sfIntRect generate_rect(int top, int left, int height, int width);
    sfVector2f scaling(sfSprite *sprite);
    void destroy2(sfSprite *s_wallpaper, sfTexture *t_wallpaper,
    sfClock *clock);
    int checking_text(sfTexture *t_wallpaper, sfTexture *texture);

#endif /* !header */
