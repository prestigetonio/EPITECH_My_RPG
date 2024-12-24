/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** player
*/

#include "my.h"

static void anim_player_second(player_t *player, int dir)
{
    if (dir != -1) {
        player->rect.top = (dir * player->rect.height) + 16;
        player->rect.left = (player->rect.width + player->rect.left) * 2;
        if (player->rect.left >= 175) {
            player->rect.left = 16;
        }
        sfSprite_setTextureRect(player->player, player->rect);
    } else {
        player->rect.top = 16;
        player->rect.left = 92;
        sfSprite_setTextureRect(player->player, player->rect);
    }
}

static void anim_player(player_t *player)
{
    int dir = -1;

    if (sfKeyboard_isKeyPressed(sfKeyS))
        dir = 0;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        dir = 1;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        dir = 2;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        dir = 3;
    if (sfTime_asSeconds(sfClock_getElapsedTime(player->time)) >= 0.20) {
        anim_player_second(player, dir);
        sfClock_restart(player->time);
    }
    if (dir != -1 && sfSound_getStatus(player->walk) != sfPlaying) {
        sfSound_play(player->walk);
    }
}

static sfVector2f calcule_len(need_t *need)
{
    sfVector2u size = sfRenderWindow_getSize(need->win);
    sfVector2f scale = sfSprite_getScale(need->player->player);
    float x = 1920;
    float y = 1080;

    x = ((size.x * (100 / x)) / 100);
    y = ((size.y * (100 / y)) / 100);
    scale.x = 0.5 / x;
    scale.y = 0.5 / y;
    return (scale);
}

static void follow_player(need_t *need)
{
    sfVector2f sprite_pos = sfSprite_getPosition(need->player->player);
    sfVector2f center = {400, 300};

    sfSprite_setScale(need->player->player, calcule_len(need));
    sfView_setCenter(need->player->view, center);
    sfView_setSize(need->player->view, (sfVector2f){1920, 1080});
    sfView_setCenter(need->player->view, sprite_pos);
    sfRenderWindow_setView(need->win, need->player->view);
}

static void move_play_function(need_t *need, float x, float y)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        x -= 0.1;
        attack(need, 1);
        if (sfKeyboard_isKeyPressed(sfKeyLShift))
            x -= 0.1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        x += 0.1;
        attack(need, 2);
        if (sfKeyboard_isKeyPressed(sfKeyLShift))
            x += 0.1;
    }
    if (x != 0 && y != 0) {
        x *= 0.7071f;
        y *= 0.7071f;
    }
    sfSprite_move(need->player->player, (sfVector2f){x, y});
    anim_player(need->player);
    follow_player(need);
    sfRenderWindow_drawSprite(need->win, need->player->player, NULL);
}

void move_player(need_t *need)
{
    float x = 0;
    float y = 0;

    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        y -= 0.1;
        attack(need, 3);
        if (sfKeyboard_isKeyPressed(sfKeyLShift))
            y -= 0.1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        y += 0.1;
        attack(need, 0);
        if (sfKeyboard_isKeyPressed(sfKeyLShift))
            y += 0.1;
    }
    move_play_function(need, x, y);
}
