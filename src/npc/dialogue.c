/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** dialogue
*/

#include "my.h"
#include "rat.h"

static sfVector2f calcule_len(need_t *need)
{
    sfVector2u size = sfRenderWindow_getSize(need->win);
    int index = need->pnj->txt->index;
    sfVector2f scale = sfSprite_getScale(need->pnj->txt->mess[index]);
    float x = 1920;
    float y = 1080;

    x = ((size.x * (100 / x)) / 100);
    y = ((size.y * (100 / y)) / 100);
    scale.x = 0.35 / x;
    scale.y = 0.35 / y;
    return (scale);
}

static int check_hitbox(need_t *need)
{
    sfFloatRect pnj_rec = sfSprite_getGlobalBounds(need->pnj->pnj);
    sfVector2f player_pos = sfSprite_getPosition(need->player->player);

    pnj_rec.left -= 30;
    pnj_rec.top -= 30;
    pnj_rec.width += 30;
    pnj_rec.height += 30;
    if (sfFloatRect_contains(&pnj_rec, player_pos.x, player_pos.y)) {
        if (sfSound_getStatus(need->pnj->txt->talk) != sfPlaying) {
            sfSound_play(need->pnj->txt->talk);
        }
        return (1);
    } else {
        return (0);
    }
}

static void change_mess(need_t *need)
{
    if (sfKeyboard_isKeyPressed(sfKeyY)) {
        need->pnj->txt->index = 1;
        need->pnj->booleen = 1;
        need->mob = create_rat();
    } else if (sfKeyboard_isKeyPressed(sfKeyN)) {
        need->pnj->txt->index = 2;
        need->pnj->booleen = 0;
    }
}

static void to_many_char(need_t *need, int i)
{
    if (need->pnj->booleen == 0) {
        sfRenderWindow_drawSprite(need->win, need->pnj->txt->mess[i], NULL);
    }
}

void display_text(need_t *need)
{
    sfVector2f pnj_pos = sfSprite_getPosition(need->pnj->pnj);
    int i = need->pnj->txt->index;

    pnj_pos.y -= 150;
    if (check_hitbox(need) == 1) {
        sfSprite_setScale(need->pnj->txt->mess[i], calcule_len(need));
        if (need->pnj->txt->index == 0 && need->pnj->booleen == 0)
            change_mess(need);
        sfSprite_setPosition(need->pnj->txt->mess[i], pnj_pos);
        i = need->pnj->txt->index;
        to_many_char(need, i);
    } else {
        need->pnj->txt->index = 0;
    }
}
