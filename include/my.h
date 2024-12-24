/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h
*/

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include "rat.h"

typedef struct text_s {
    sfSprite *mess[3];
    int index;
    sfSound *talk;
    sfSoundBuffer *buff;
} text_t;

typedef struct pnj_s {
    sfSprite *pnj;
    sfIntRect rect;
    text_t *txt;
    sfClock *time;
    int booleen;
} pnj_t;

typedef struct stat_s {
    int pv;
    int xp;
    int lvl;
    int pa;
    sfSprite *attack;
    sfClock *t;
} stat_t;

typedef struct player_s {
    sfSprite *player;
    stat_t *stat;
    sfIntRect rect;
    sfClock *time;
    sfView *view;
    sfSound *walk;
    sfSoundBuffer *buff;
} player_t;

typedef struct need_s {
    sfRenderWindow *win;
    sfEvent event;
    player_t *player;
    pnj_t *pnj;
    mob_t mob;
    sfSprite *map;
} need_t;

#ifndef MY_H_
    #define MY_H_

need_t *define_needed(void);
void destroy_needed(need_t *need);

player_t *create_player(void);
void destroy_player(player_t *player);
void move_player(need_t *player);
void attack(need_t *need, int dir);

mob_t create_rat(void);
mob_t rat_manager(mob_t rat, int x, int y);
void destroy_mob(mob_t mob);

pnj_t *create_pnj(void);
void destroy_pnj(pnj_t *pnj);
void display_pnj(need_t *need);
void display_text(need_t *need);

void display_map(need_t *need);

#endif /* MY_H_ */
