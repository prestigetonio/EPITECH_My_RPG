/*
** EPITECH PROJECT, 2028
** Rat
** File description:
** destroy_mob
*/

#include "rat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

void destroy_mob(mob_t mob)
{
    sfSprite_destroy(mob.sprite);
    sfClock_destroy(mob.clock);
    sfClock_destroy(mob.mv_clock);
    return;
}
