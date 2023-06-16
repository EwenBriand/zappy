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
#include "init_dest.h"

static int id_act = 0;

egg_t *init_egg(main_t *main, int i)
{
    static int id = 0;
    egg_t *new = malloc(sizeof(egg_t));

    if (new == NULL)
        return (NULL);

    srand(time(NULL) + i);
    new->coord = malloc(sizeof(coord_t));
    new->coord->x = rand() % main->args->width;
    new->coord->y = rand() % main->args->height;
    new->team = strdup(main->args->name[i]);
    new->orientation = rand() % 4;
    new->id = id++;
    main->teams_list[i]->max_player++;

    printf("Egg created at %d %d with %d oritentation from %s team\n",
        new->coord->x, new->coord->y, new->orientation, new->team);

    dprintf(main->server->gui_fd, "pfk -1\n");
    dprintf(main->server->gui_fd, "enw %d %d %d %d\n", new->id, -1,
        new->coord->x, new->coord->y);

    return (new);
}

egg_t *init_egg_from_cli(main_t *main, int i)
{
    static int id = 0;
    egg_t *new = malloc(sizeof(egg_t));

    if (new == NULL)
        return (NULL);

    new->coord = malloc(sizeof(coord_t));
    new->coord->x = CURR_CLI->player->coord->x;
    new->coord->y = CURR_CLI->player->coord->y;
    new->team = strdup(main->teams_list[i]->name);
    new->orientation = CURR_CLI->player->orientation;
    new->id = id++;
    main->teams_list[i]->max_player++;

    printf("Egg created at %d %d with %d oritentation from %s team\n",
        new->coord->x, new->coord->y, new->orientation, new->team);

    dprintf(main->server->gui_fd, "enw %d %d %d %d\r\n", new->id,
        CURR_CLI->player->id, new->coord->x, new->coord->y);

    return (new);
}

void destroy_egg(egg_t *egg)
{
    free(egg->team);
    free(egg);
}

player_t *init_player(egg_t *egg, main_t *main)
{
    player_t *new = malloc(sizeof(player_t));

    if (new == NULL)
        return (NULL);
    new->id = id_act++;
    new->coord = malloc(sizeof(coord_t));
    new->coord->x = egg->coord->x;
    new->coord->y = egg->coord->y;
    new->orientation = egg->orientation;
    new->time = 0;
    new->command_time = 0;
    new->living_time = 126;
    new->status_cmd = 0;
    new->locked = false;
    new->id_player_inc = NULL;

    new->inventory = malloc(sizeof(int) * 7);
    new->inventory[Q0] = 9;
    for (int i = 1; i < 7; ++i)
        new->inventory[i] = 0;
    new->level = 1;
    new->cmd_buf = malloc(sizeof(char *) * 11);
    for (int i = 0; i < 11; ++i)
        new->cmd_buf[i] = NULL;

    printf("Player %d created at %d %d with %d oritentation at level %d\n",
        new->id, new->coord->x, new->coord->y, new->orientation, new->level);

    dprintf(main->server->gui_fd, "pnw #%d %d %d %d %d %s\n", new->id,
        new->coord->x, new->coord->y, new->orientation, new->level, egg->team);

    return (new);
}

player_t *init_player_char(main_t *main)
{
    player_t *new = malloc(sizeof(player_t));

    if (new == NULL) {
        return (NULL);
    }
    new->id = id_act++;
    int *pos = malloc(sizeof(int) * 2);

    get_random_pos(main, pos);
    new->coord = malloc(sizeof(coord_t));
    new->coord->x = pos[0];
    new->coord->y = pos[1];
    new->orientation = rand() % 4;
    new->time = 0;
    new->command_time = 0;
    new->status_cmd = 0;
    new->living_time = 126;
    new->locked = false;
    new->id_player_inc = NULL;

    new->inventory = malloc(sizeof(int) * 7);
    new->inventory[Q0] = 9;
    for (int i = 1; i < 7; ++i)
        new->inventory[i] = 0;
    new->level = 1;
    new->cmd_buf = malloc(sizeof(char *) * 11);
    for (int i = 0; i < 11; ++i)
        new->cmd_buf[i] = NULL;

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
    free(player);
}
