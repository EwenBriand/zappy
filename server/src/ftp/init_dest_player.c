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

    new->coord[X] = egg->coord[X];
    new->coord[Y] = egg->coord[Y];
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

    return (new);
}
