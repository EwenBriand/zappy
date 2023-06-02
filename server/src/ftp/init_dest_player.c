/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** init_dest_player
*/

#include <stdlib.h>
#include <time.h>
#include "ftp.h"
#include "server.h"

egg_t *init_egg(main_t *main, int i)
{
    egg_t *new = malloc(sizeof(egg_t));

    if (new == NULL)
        return (NULL);

    srand(time(NULL) + i);
    new->coord.x = rand() % main->args->width;
    new->coord.y = rand() % main->args->height;
    new->team = strdup(main->args->name[i]);
    // new->orientation = rand() % 4; // TODO rand
    new->orientation = 0;

    printf("Egg created at %d %d with %d oritentation from %s team\n",
        new->coord.x, new->coord.y, new->orientation, new->team);

    return (new);
}

void destroy_egg(egg_t *egg)
{
    free(egg->team);
    free(egg);
}

player_t *init_player(egg_t *egg)
{
    player_t *new = malloc(sizeof(player_t));
    static int id = 0;
    if (new == NULL)
        return (NULL);
    new->id = id++;
    new->coord.x = egg->coord.x;
    new->coord.y = egg->coord.y;
    new->orientation = egg->orientation;
    new->team = egg->team;
    new->inventory[Q0] = 1260;
    for (int i = 1; i < 7; ++i)
        new->inventory[i] = 0;
    new->level = 1;
    new->cmd_buf = malloc(sizeof(char *) * 11);
    for (int i = 0; i < 11; ++i)
        new->cmd_buf[i] = NULL;

    return (new);
}

void destroy_player(player_t *player)
{
    free(player->team);
    free(player);
    for (int i = 0; i < 11; ++i)
        if (player->cmd_buf[i] != NULL)
            free(player->cmd_buf[i]);
}
