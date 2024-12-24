/*
** EPITECH PROJECT, 2028
** Rat
** File description:
** display_mob
*/

#include "rat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

static mob_t animate_sprite(mob_t rat)
{
    if (rat.sp == 0) {
        rat.size = (sfIntRect){32 * 0, 32, 32, 32};
        rat.sp = 1;
        return rat;
    }
    if (rat.sp == 1) {
        rat.size = (sfIntRect){32 * 1, 32, 32, 32};
        rat.sp = 2;
        return rat;
    }
    if (rat.sp == 2) {
        rat.size = (sfIntRect){32 * 2, 32, 32, 32};
        rat.sp = 3;
        return rat;
    }
    if (rat.sp == 3) {
        rat.size = (sfIntRect){32 * 3, 32, 32, 32};
        rat.sp = 0;
        return rat;
    }
}

static mob_t mob_display(mob_t rat, int x)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(rat.clock)) >= 167) {
        rat = animate_sprite(rat);
        sfClock_restart(rat.clock);
    }
    sfSprite_setTextureRect(rat.sprite, rat.size);
    if (x < rat.x) {
        sfSprite_setScale(rat.sprite, (sfVector2f){1.5f, 1.5f});
        sfSprite_setPosition(rat.sprite, (sfVector2f){rat.x - 16, rat.y});
    } else {
        sfSprite_setScale(rat.sprite, (sfVector2f){-1.5f, 1.5f});
        sfSprite_setPosition(rat.sprite, (sfVector2f){rat.x + 16, rat.y});
    }
    return rat;
}

static mob_t mv_mob(mob_t rat, int x, int y)
{
    int speed = rat.stats.mv_speed;

    if (sfTime_asMilliseconds(sfClock_getElapsedTime(rat.mv_clock)) >= 8.35) {
        if (x != rat.x)
            rat.x = rat.x < x ? rat.x + speed : rat.x - speed;
        if (y != rat.y)
            rat.y = rat.y < y ? rat.y + speed : rat.y - speed;
    sfClock_restart(rat.mv_clock);
    }
    return rat;
}

mob_t rat_manager(mob_t rat, int x, int y)
{
    rat = mob_display(rat, x);
    rat = mv_mob(rat, x, y);
    return rat;
}
