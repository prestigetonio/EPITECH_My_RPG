/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** create
*/

#include "my.h"

static void set_texture(text_t *text, char *t[3])
{
    sfTexture *texture1 = sfTexture_createFromFile(t[0], NULL);
    sfTexture *texture2 = sfTexture_createFromFile(t[1], NULL);
    sfTexture *texture3 = sfTexture_createFromFile(t[2], NULL);
    sfVector2f scale = {0.35, 0.35};
    sfVector2f pos = {650, 355};

    for (int i = 0; i < 3; i++) {
        text->mess[i] = sfSprite_create();
        sfSprite_setPosition(text->mess[i], pos);
        sfSprite_setScale(text->mess[i], scale);
    }
    sfSprite_setTexture(text->mess[0], texture1, sfTrue);
    sfSprite_setTexture(text->mess[1], texture2, sfTrue);
    sfSprite_setTexture(text->mess[2], texture3, sfTrue);
}

static text_t *create_text(void)
{
    text_t *text = malloc(sizeof(text_t));
    char *t[3] = {"./assets/b1.png", "./assets/b2.png", "./assets/b3.png"};
    char *talk = "./assets/sound/npc.ogg";

    text->index = 0;
    set_texture(text, t);
    text->talk = sfSound_create();
    text->buff = sfSoundBuffer_createFromFile(talk);
    sfSound_setBuffer(text->talk, text->buff);
    sfSound_setVolume(text->talk, 100);
    return (text);
}

static sfSprite *define_pnj(void)
{
    sfTexture *text = sfTexture_createFromFile("./assets/pnj1.png", NULL);
    sfSprite *pnj = sfSprite_create();
    sfVector2f scale = {0.5, 0.5};
    sfVector2f pos = {650, 355};
    sfIntRect rect = {8, 12, 75, 118};

    sfSprite_setTexture(pnj, text, sfTrue);
    sfSprite_setTextureRect(pnj, rect);
    sfSprite_setScale(pnj, scale);
    sfSprite_setPosition(pnj, pos);
    return (pnj);
}

pnj_t *create_pnj(void)
{
    struct pnj_s *pnj = malloc(sizeof(pnj_t));

    pnj->pnj = define_pnj();
    pnj->rect.left = 8;
    pnj->rect.top = 12;
    pnj->rect.width = 75;
    pnj->rect.height = 118;
    pnj->txt = create_text();
    pnj->time = sfClock_create();
    pnj->booleen = 0;
    return (pnj);
}
