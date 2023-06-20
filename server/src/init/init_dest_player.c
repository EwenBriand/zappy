/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** init_dest_player
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ftp.h"
#include "server.h"
#include "string.h"
#include "init_dest.h"

static void init_const_player(player_t *new, main_t *main)
{
    new->id = main->id_act++;
    new->time = 0;
    new->command_time = 0;
    new->status_cmd = 0;
    new->living_time = 126;
    new->locked = false;
    new->id_player_inc = NULL;

    new->inventory = malloc(sizeof(int) * 7);
    new->inventory[Q0] = 9;
    for (int i = 1; i < 7; ++i)
        new->inventory[i] = 10;
    new->level = 1;
    new->act_cmd = NULL;
    new->cmd_buf = malloc(sizeof(char *) * 11);
    for (int i = 0; i < 11; ++i)
        new->cmd_buf[i] = NULL;
}

player_t *init_player(egg_t *egg, main_t *main)
{
    player_t *new = malloc(sizeof(player_t));

    if (new == NULL)
        return (NULL);

    new->coord = malloc(sizeof(coord_t));
    new->coord->x = egg->coord->x;
    new->coord->y = egg->coord->y;
    new->orientation = egg->orientation;

    init_const_player(new, main);

    printf("Player %d created at %d %d with %d oritentation at level %d\n",
        new->id, new->coord->x, new->coord->y, new->orientation, new->level);

    dprintf(main->server->gui_fd, "pnw #%d %d %d %d %d %s\n", new->id,
        new->coord->x, new->coord->y, new->orientation, new->level, egg->team);

    return (new);
}

player_t *init_player_char(main_t *main)
{
    player_t *new = malloc(sizeof(player_t));

    if (new == NULL)
        return (NULL);

    int *pos = malloc(sizeof(int) * 2);

    get_random_pos(main, pos);
    new->coord = malloc(sizeof(coord_t));
    new->coord->x = pos[0];
    new->coord->y = pos[1];
    new->orientation = rand() % 4;

    init_const_player(new, main);

    printf("Player %d created at %d %d with %d oritentation at level %d\n",
        new->id, new->coord->x, new->coord->y, new->orientation, new->level);
    free(pos);
    return (new);
}

void destroy_player(player_t *player)
{
    free(player->inventory);
    for (int i = 0; i < 11; ++i)
        if (player->cmd_buf[i] != NULL)
            free(player->cmd_buf[i]);

    if (player->act_cmd != NULL)
        free(player->act_cmd);
    if (player->id_player_inc != NULL)
        free(player->id_player_inc);
    free(player->cmd_buf);
    free(player->coord);
    free(player);
}
