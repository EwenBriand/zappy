/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** init_egg
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ftp.h"
#include "server.h"
#include "string.h"
#include "init_dest.h"

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
    free(egg->coord);
    free(egg->team);
    free(egg);
}
