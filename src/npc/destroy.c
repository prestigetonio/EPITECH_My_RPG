/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** destroy
*/

#include "my.h"

static void destroy_text(text_t *text)
{
    sfSprite_destroy(text->mess[0]);
    sfSprite_destroy(text->mess[1]);
    sfSprite_destroy(text->mess[2]);
    sfSound_destroy(text->talk);
    sfSoundBuffer_destroy(text->buff);
    text->index = 0;
    free(text);
}

void destroy_pnj(pnj_t *pnj)
{
    sfSprite_destroy(pnj->pnj);
    pnj->rect.left = 0;
    pnj->rect.top = 0;
    pnj->rect.width = 0;
    pnj->rect.height = 0;
    destroy_text(pnj->txt);
    sfClock_destroy(pnj->time);
    pnj->booleen = 0;
    free(pnj);
}
