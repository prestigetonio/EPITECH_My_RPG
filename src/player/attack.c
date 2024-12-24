/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-maxime.huet
** File description:
** attack
*/

#include "my.h"

void touch(need_t *need)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(need->player->player);
    float t = sfTime_asSeconds(sfClock_getElapsedTime(need->player->stat->t));

    rect.left -= 25;
    rect.top -= 25;
    rect.width += 40;
    rect.height += 40;
    if (t >= 0.25) {
        if (sfFloatRect_contains(&rect, need->mob.x, need->mob.y)) {
            need->mob.stats.health -= need->player->stat->pa;
        }
        if (need->mob.stats.health <= 0) {
            destroy_mob(need->mob);
            need->player->stat->lvl += 1;
            need->player->stat->pa += 1;
            need->pnj->booleen = 0;
        }
        sfClock_restart(need->player->stat->t);
    }
}

void attack(need_t *need, int dir)
{
    sfVector2f pos = sfSprite_getPosition(need->player->player);

    if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
        if (dir == 0)
            pos = (sfVector2f){pos.x - 10, pos.y + 60};
        if (dir == 1)
            pos = (sfVector2f){pos.x - 50, pos.y};
        if (dir == 2)
            pos = (sfVector2f){pos.x + 30, pos.y};
        if (dir == 3)
            pos = (sfVector2f){pos.x - 10, pos.y - 40};
        sfSprite_setPosition(need->player->stat->attack, pos);
        sfRenderWindow_drawSprite(need->win, need->player->stat->attack, NULL);
        if (need->pnj->booleen == 1) {
            touch(need);
        }
    }
}
