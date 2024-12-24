/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** collision
*/

#include "my.h"

static sfVector2f calcule_len(need_t *need)
{
    sfVector2u size = sfRenderWindow_getSize(need->win);
    sfVector2f scale = sfSprite_getScale(need->map);
    float x = 1920;
    float y = 1080;

    x = ((size.x * (100 / x)) / 100);
    y = ((size.y * (100 / y)) / 100);
    scale.x = 1 / x;
    scale.y = 1 / y;
    return (scale);
}

void display_map(need_t *need)
{
    sfSprite_setScale(need->map, calcule_len(need));
    sfRenderWindow_drawSprite(need->win, need->map, NULL);
}
