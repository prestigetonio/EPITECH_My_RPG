/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** manage
*/

#include "my.h"

static sfSprite *define_player(void)
{
    sfTexture *txt = sfTexture_createFromFile("assets/player.png", NULL);
    sfSprite *ply = sfSprite_create();
    sfVector2f scale = {0.5, 0.5};
    sfVector2f pos = {800, 800};
    sfIntRect rec = {92, 16, 66, 118};

    sfSprite_setTexture(ply, txt, sfTrue);
    sfSprite_setTextureRect(ply, rec);
    sfSprite_setScale(ply, scale);
    sfSprite_setPosition(ply, pos);
    return (ply);
}

static stat_t *define_stat(void)
{
    stat_t *stat = malloc(sizeof(stat_t));
    sfTexture *texture = sfTexture_createFromFile("./assets/attack.png", NULL);
    sfVector2f pos = {600, 600};
    sfVector2f scale = {0.1, 0.1};

    stat->pv = 25;
    stat->xp = 0;
    stat->lvl = 0;
    stat->pa = 1;
    stat->attack = sfSprite_create();
    stat->t = sfClock_create();
    sfSprite_setTexture(stat->attack, texture, sfTrue);
    sfSprite_setScale(stat->attack, scale);
    sfSprite_setPosition(stat->attack, pos);
    return (stat);
}

player_t *create_player(void)
{
    player_t *player = malloc(sizeof(player_t));
    char *walk = "assets/sound/walk.ogg";

    player->player = define_player();
    player->stat = define_stat();
    player->rect = (sfIntRect){92, 16, 66, 118};
    player->time = sfClock_create();
    player->view = sfView_create();
    player->walk = sfSound_create();
    player->buff = sfSoundBuffer_createFromFile(walk);
    sfSound_setBuffer(player->walk, player->buff);
    sfSound_setVolume(player->walk, 100);
    return (player);
}

static void destroy_stat(stat_t *stat)
{
    stat->pv = 0;
    stat->xp = 0;
    stat->lvl = 0;
    stat->pa = 0;
    sfSprite_destroy(stat->attack);
    sfClock_destroy(stat->t);
    free(stat);
}

void destroy_player(player_t *player)
{
    sfSprite_destroy(player->player);
    destroy_stat(player->stat);
    sfClock_destroy(player->time);
    sfView_destroy(player->view);
    sfSound_destroy(player->walk);
    sfSoundBuffer_destroy(player->buff);
    free(player);
}
