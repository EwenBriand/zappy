/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** init_dest_player
*/

#include "ftp.h"
#include "server.h"

player_t *init_player(egg_t *egg)
{
    player_t *new = malloc(sizeof(player_t));

    if (new == NULL)
        return (NULL);

    new->coord.x = egg->coord.x;
    new->coord.y = egg->coord.y;
    new->orientation = egg->orientation;
    new->team = egg->team;
    new->inventory[0] = 10;
    new->inventory[1] = 0;
    new->inventory[2] = 0;
    new->inventory[3] = 0;
    new->inventory[4] = 0;
    new->inventory[5] = 0;
    new->inventory[6] = 0;
    new->level = 1;
    new->food = 126;
    new->cmd_buf = malloc(sizeof(char *) * 11);
    for (int i = 0; i < 11; ++i)
        new->cmd_buf[i] == NULL;

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
