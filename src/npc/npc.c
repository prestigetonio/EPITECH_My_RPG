/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** npc
*/

#include "my.h"
#include "rat.h"

static sfVector2f calcule_len(need_t *need)
{
    sfVector2u size = sfRenderWindow_getSize(need->win);
    sfVector2f scale = sfSprite_getScale(need->pnj->pnj);
    float x = 1920;
    float y = 1080;

    x = ((size.x * (100 / x)) / 100);
    y = ((size.y * (100 / y)) / 100);
    scale.x = 0.5 / x;
    scale.y = 0.5 / y;
    return (scale);
}

void manage_mob(need_t *need)
{
    sfVector2f pos = sfSprite_getPosition(need->player->player);

    if (need->pnj->booleen == 1) {
        need->mob = rat_manager(need->mob, pos.x, pos.y);
        sfRenderWindow_drawSprite(need->win, need->mob.sprite, NULL);
    }
}

void display_pnj(need_t *need)
{
    display_text(need);
    manage_mob(need);
    sfSprite_setScale(need->pnj->pnj, calcule_len(need));
    sfRenderWindow_drawSprite(need->win, need->pnj->pnj, NULL);
    if (sfTime_asSeconds(sfClock_getElapsedTime(need->pnj->time)) >= 0.20) {
        if (need->pnj->rect.left == 168) {
            need->pnj->rect.left = 8;
        } else {
            sfSprite_setTextureRect(need->pnj->pnj, need->pnj->rect);
            need->pnj->rect.left += 80;
        }
        sfClock_restart(need->pnj->time);
    }
}
