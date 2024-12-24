/*
** EPITECH PROJECT, 2028
** Rat
** File description:
** rat
*/

#include <SFML/Graphics.h>
#include <SFML/System/Time.h>

#ifndef RAT_H_
    #define RAT_H_
typedef struct mob_stat_s {
    int health;
    int mv_speed;
    int dmg;
    int getting_hitted;
} mob_stat_t;

typedef struct mob_s {
    mob_stat_t stats;
    sfIntRect size;
    sfSprite *sprite;
    int sp;
    sfClock *clock;
    int x;
    int y;
    sfClock *mv_clock;
} mob_t;

#endif /* !RAT_H_ */
