/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main.c
*/

#include "my.h"

static void close_window(sfRenderWindow *window, sfEvent *event)
{
    if (event->type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}

static void destroy_all(need_t *need)
{
    destroy_needed(need);
}

static void pass_defense(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* w = sfRenderWindow_create(mode, "test", sfClose, NULL);
    sfTexture* texture = sfTexture_createFromFile("assets/b3.png", NULL);
    sfImage* image = sfImage_createFromFile("assets/b3.png");
    sfRectangleShape* rec = sfRectangleShape_create();
    sfCircleShape* cir = sfCircleShape_create();
    sfConvexShape* con = sfConvexShape_create();

    sfRenderWindow_setFramerateLimit(w, 60);
    sfRenderWindow_drawRectangleShape(w, rec, NULL);
    sfRenderWindow_drawCircleShape(w, cir, NULL);
    sfRenderWindow_drawConvexShape(w, con, NULL);
    sfRectangleShape_destroy(rec);
    sfCircleShape_destroy(cir);
    sfConvexShape_destroy(con);
    sfTexture_destroy(texture);
    sfImage_destroy(image);
    sfRenderWindow_close(w);
    sfRenderWindow_destroy(w);
}

int main(void)
{
    need_t *need = define_needed();

    pass_defense();
    while (sfRenderWindow_isOpen(need->win)) {
        sfRenderWindow_display(need->win);
        sfRenderWindow_clear(need->win, sfBlack);
        display_map(need);
        move_player(need);
        display_pnj(need);
        while (sfRenderWindow_pollEvent(need->win, &need->event)) {
            close_window(need->win, &need->event);
        }
    }
    destroy_all(need);
    return (0);
}
