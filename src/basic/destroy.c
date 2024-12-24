/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** destroy_basic
*/

#include "my.h"

void destroy_needed(need_t *need)
{
    sfRenderWindow_close(need->win);
    sfRenderWindow_destroy(need->win);
    destroy_player(need->player);
    sfSprite_destroy(need->map);
    if (need->pnj->booleen == 1) {
        destroy_mob(need->mob);
    }
    destroy_pnj(need->pnj);
    free(need);
}
