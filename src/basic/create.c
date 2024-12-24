/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** create_basic
*/

#include "my.h"

sfSprite *create_map(void)
{
    sfTexture* texture = sfTexture_createFromFile("assets/map.png", NULL);
    sfSprite* map = sfSprite_create();
    sfVector2f scale = {1, 1};

    sfSprite_setTexture(map, texture, sfTrue);
    sfSprite_setScale(map, scale);
    return (map);
}

need_t *define_needed(void)
{
    struct need_s *need = malloc(sizeof(need_t));
    sfVideoMode mode = {1920, 1080, 64};

    need->win = sfRenderWindow_create(mode, "RPG", sfResize | sfClose, NULL);
    need->player = create_player();
    need->map = create_map();
    need->pnj = create_pnj();
    return (need);
}
