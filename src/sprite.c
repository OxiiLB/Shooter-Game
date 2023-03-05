/*
** EPITECH PROJECT, 2022
** sprite.c
** File description:
** Create a sprite with CSFML library.
*/

#include "header.h"
#include "my.h"
#include <SFML/Window.h>
#include <SFML/Graphics.h>

sfIntRect generate_rect(int top, int left, int height, int width)
{
    sfIntRect rect;
    rect.top = top;
    rect.left = left;
    rect.height = height;
    rect.width = width;
    return rect;
}

sfSprite *create_sprite(sfVector2f position, sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, position);
    return sprite;
}
