/*
** EPITECH PROJECT, 2022
** checking_text
** File description:
** check if the textures is null or not
*/

#include "my.h"
#include "header.h"
#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/System/Export.h>

int checking_text(sfTexture *t_wallpaper, sfTexture *texture)
{
    if (t_wallpaper == NULL || texture == NULL) {
        write(2, "Sprite not found\n", 18);
        return 84;
    }
    return 0;
}
