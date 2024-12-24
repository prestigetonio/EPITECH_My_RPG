/*
** EPITECH PROJECT, 2028
** Rat
** File description:
** create_mob
*/

#include "rat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

mob_stat_t create_stat(void)
{
    mob_stat_t stat = {0};

    stat.health = 5;
    stat.mv_speed = 1;
    stat.dmg = 3;
    stat.getting_hitted = 0;
    return stat;
}

mob_t create_rat(void)
{
    mob_t rat = {0};
    sfTexture *texture;

    rat.stats = create_stat();
    rat.size = (sfIntRect) {0, 32, 32, 64};
    texture = sfTexture_createFromFile("./assets/rats.png", NULL);
    rat.sprite = sfSprite_create();
    sfSprite_setTexture(rat.sprite, texture, sfTrue);
    rat.clock = sfClock_create();
    rat.mv_clock = sfClock_create();
    rat.x = 400;
    rat.y = 300;
    return rat;
}
